class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        
        for (char c : s) {
            if (c == '(') {
                mini++;
                maxi++;
            } else if (c == ')') {
                mini--;
                maxi--;
            } else { // c == '*'
                mini--;
                maxi++;
            }
            
            // If at any point maxi is negative, there are too many ')'
            if (maxi < 0) return false;
            
            // mini cannot be less than 0 (we can't owe closing brackets)
            if (mini < 0) mini = 0;
        }
        
        // If mini is 0, we can validly form a balanced string
        return mini == 0;
    }
};