#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_x = -1, start_y = -1;
        vector<pair<int, int>> litters;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int num_litter = litters.size();
        if (num_litter == 0) return 0;
        
        int litter_map[20][20];
        memset(litter_map, -1, sizeof(litter_map));
        for (int i = 0; i < num_litter; ++i) {
            litter_map[litters[i].first][litters[i].second] = i;
        }
        
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << num_litter, -1)));
        queue<tuple<int, int, int, int, int>> q;
        
        q.push({start_x, start_y, 0, energy, 0});
        bestEnergy[start_x][start_y][0] = energy;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int full_mask = (1 << num_litter) - 1;
        
        while (!q.empty()) {
            auto [x, y, mask, curr_e, steps] = q.front();
            q.pop();
            
            if (mask == full_mask) {
                return steps;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') {
                    continue;
                }
                
                // You must have at least 1 energy to take a step
                if (curr_e < 1) {
                    continue;
                }
                
                int next_e = curr_e - 1;
                int next_mask = mask;
                int l_idx = litter_map[nx][ny];
                if (l_idx != -1) {
                    next_mask |= (1 << l_idx);
                }
                
                int final_e = (classroom[nx][ny] == 'R') ? energy : next_e;
                
                if (final_e > bestEnergy[nx][ny][next_mask]) {
                    bestEnergy[nx][ny][next_mask] = final_e;
                    q.push({nx, ny, next_mask, final_e, steps + 1});
                }
            }
        }
        
        return -1;
    }
};