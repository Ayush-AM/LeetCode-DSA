class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // check vertical (only above)
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {

        // base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // place
                board[row][col] = 'Q';

                // move to next row
                solve(row + 1, n, board, ans);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // initialize board
        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);

        return ans;
    }
};