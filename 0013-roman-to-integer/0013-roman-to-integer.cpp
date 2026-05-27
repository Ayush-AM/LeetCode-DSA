class Solution {
public:

    int getValue(char c) {
        switch (toupper(c)) { // Convert to uppercase to handle lowercase input
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = getValue(s[i]);
            int next = getValue(s[i + 1]);
            
            if (i + 1 < s.length() && curr < next)
                sum -= curr;
            else
                sum += curr;
        }
        return sum;
    }
};