// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string>matrix(m,string(n,'#'));
//         for (int i = 0; i < m; ++i) {       // Loop through rows
//             for (int j = 0; j < n; ++j) {   // Loop through columns
//                 if (i == 0 || j == n - 1) {
//                     matrix[i][j] = '.';
//                 }
               
//             }
//         }
//         return matrix;
//     }
// };

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initialize grid of size m x n with '#'
        vector<string> grid(m, string(n, '#'));
        
        // 1. Make the top row free cells '.'
        grid[0] = string(n, '.');
        
        // 2. Make the rightmost column free cells '.'
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};