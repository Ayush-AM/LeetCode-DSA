class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c: s){
            if(c == '('){
                st.push(')');
            }
            else if(c == '{'){
                st.push('}');
            }
            else if(c == '['){
                st.push(']');
            }
            else{
                if(st.empty() || st.top() != c){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();

    }
};

/*
class Solution {
    public:
        bool isValid(string str) {
            stack<char> st;

            for(int i=0; i<str.size(); i++) {
                if(str[i] == '(' || str[i] == '{' || str[i] == '[') { //opening
                    st.push(str[i]);
                } else { //closing
                    if(st.size() == 0) {
                        return false;
                    }

                    if((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {
                        st.pop();
                    } else { //no match
                        return false;
                    }
                }
            }
            
            // The image cuts off here, but you need this to check if 
            // there are any unmatched opening brackets left over:
            return st.empty(); 
        }
    };
*/