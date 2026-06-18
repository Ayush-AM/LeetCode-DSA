class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--;
                max_open++;
            }
            
            // If at any point max_open is negative, there are too many ')'
            if (max_open < 0) return false;
            
            // min_open cannot be less than 0 (we can't owe closing brackets)
            if (min_open < 0) min_open = 0;
        }
        
        // If min_open is 0, we can validly form a balanced string
        return min_open == 0;
    }
};