class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int count = 0;
        for(auto ch : s){
            if(ch == '('){
                count++;
                maxDepth = max(maxDepth, count);
            }
            else if(ch == ')'){
                count--;
            }
        }
        return maxDepth;
    }
};