class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>matrix(m,string(n,'#'));
        for (int i = 0; i < m; ++i) {       // Loop through rows
            for (int j = 0; j < n; ++j) {   // Loop through columns
                if (i == 0 || j == n - 1) {
                    matrix[i][j] = '.';
                }
               
            }
        }
        return matrix;
    }
};