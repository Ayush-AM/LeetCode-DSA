class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        for (char c : columnTitle) {
            // Convert character to its 1-indexed numerical value (A -> 1, B -> 2, etc.)
            int d = c - 'A' + 1;
            
            // Shift the current result by a factor of 26 and add the current digit
            // Using long long for result dynamically prevents integer overflow if needed,
            // but the problem constraints (length <= 7) fit within a standard 32-bit signed int.
            result = result * 26 + d;
        }
        
        return result;
    }
};