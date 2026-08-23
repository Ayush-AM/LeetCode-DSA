class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to keep track of seen numbers. 
        // 9 rows/cols/boxes, 9 possible digits ('1' to '9')
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                
                // Convert char '1'-'9' to integer index 0-8
                int val = board[r][c] - '1';
                
                // Calculate the index of the 3x3 sub-box (0 to 8)
                int box_idx = (r / 3) * 3 + (c / 3);
                
                // Check if we have already seen this digit in the current row, col, or box
                if (rows[r][val] || cols[c][val] || boxes[box_idx][val]) {
                    return false;
                }
                
                // Mark the digit as seen
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[box_idx][val] = true;
            }
        }
        
        return true;
    }
};