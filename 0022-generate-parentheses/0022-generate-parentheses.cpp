class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start with an empty string and 0 open/close brackets
        buildString("", 0, 0, n, result);
        return result;
    }

private:
    void buildString(string current, int openCount, int closeCount, int n, vector<string>& result) {
        
        // 1. THE GOAL: 
        // If our string is fully built (length is n pairs = 2*n characters)
        if (current.length() == n * 2) {
            result.push_back(current);
            return; // Stop and go back
        }

        // 2. THE OPENING RULE: 
        // If we haven't used all 'n' open brackets, we can add one.
        if (openCount < n) {
            buildString(current + "(", openCount + 1, closeCount, n, result);
        }

        // 3. THE CLOSING RULE: 
        // We can only add a close bracket if it matches an existing open bracket.
        // This means openCount must be strictly greater than closeCount.
        if (closeCount < openCount) {
            buildString(current + ")", openCount, closeCount + 1, n, result);
        }
    }
};