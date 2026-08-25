class Solution {
public:
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
        
        // 3. Convert digits and handle overflow
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check 32-bit range limits immediately
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return (int)(result * sign);
    }
};