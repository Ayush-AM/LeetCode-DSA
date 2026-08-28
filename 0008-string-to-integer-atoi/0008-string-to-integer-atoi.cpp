class Solution {
public:
    int fun(string s, int i, int sign, long long num){
        if(i>=s.size() || !isdigit(s[i])){
            return num*sign;
        }
        num = num * 10 + (s[i]-'0');

        if (sign * num > INT_MAX) return INT_MAX;
        if (sign * num < INT_MIN) return INT_MIN;
            
        return fun(s,i+1,sign,num);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // 2. Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        
        return fun(s, i, sign, 0);
    }
};