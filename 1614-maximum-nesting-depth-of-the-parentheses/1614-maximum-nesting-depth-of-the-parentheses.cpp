class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(s[i]);
                int size = st.size();
                maxDepth = max(maxDepth, size);
            }
            else if(s[i] == ')'){
                st.pop();
            }
        }
        return maxDepth;
    }
};