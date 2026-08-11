class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        string temp ="";
        int count = 0;
        for(auto ch : s){
            temp = temp + ch;
            if(ch == '(' ){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                result = result + temp.substr(1, temp.size()-2);
                temp="";
            }
        }
    return result;
    }
};