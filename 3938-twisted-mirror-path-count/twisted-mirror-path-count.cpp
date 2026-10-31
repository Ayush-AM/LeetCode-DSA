#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // Memoization table for precomputed moves:
        // target[i][j][0] for moving Right, target[i][j][1] for moving Down.
        // Stores pair<int, int> representing final (row, col) or {-1, -1} if out of bounds.
        vector<vector<vector<pair<int, int>>>> target(
            m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1}))
        );

        // Helper lambda to compute terminal landing position following mirror chain
        auto resolveMove = [&](auto& self, int r, int c, int dir) -> pair<int, int> {
            // dir = 0 (Right), dir = 1 (Down)
            int nr = r + (dir == 1 ? 1 : 0);
            int nc = c + (dir == 0 ? 1 : 0);

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                return {-1, -1}; // Out of bounds
            }

            if (grid[nr][nc] == 0) {
                return {nr, nc}; // Empty cell reached
            }

            // Hit a mirror cell (grid[nr][nc] == 1):
            // Reflection rule: Right (0) -> Down (1), Down (1) -> Right (0)
            int next_dir = 1 - dir;
            return self(self, nr, nc, next_dir);
        };

        // DP table
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0 || grid[i][j] == 1) continue;

                // Move Right (dir = 0)
                pair<int, int> land_right = resolveMove(resolveMove, i, j, 0);
                if (land_right.first != -1) {
                    dp[land_right.first][land_right.second] = 
                        (dp[land_right.first][land_right.second] + dp[i][j]) % MOD;
                }

                // Move Down (dir = 1)
                pair<int, int> land_down = resolveMove(resolveMove, i, j, 1);
                if (land_down.first != -1) {
                    dp[land_down.first][land_down.second] = 
                        (dp[land_down.first][land_down.second] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};