class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_brackets = 0;   // Tracks unmatched '('
        int unmatched_close = 0; // Tracks unmatched ')'

        for(char it : s){
            if(it == '('){
                open_brackets++;
            } else if(it == ')'){
                if(open_brackets > 0){
                    // We have an open bracket to match this closing one
                    open_brackets--; 
                } else {
                    // No open bracket to match, so this closing one is unmatched
                    unmatched_close++;
                }
            }
        }
        
        // Total additions needed are the remaining unmatched brackets of both types
        return open_brackets + unmatched_close; 
    }
};