class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();

        vector<bool> dp(n+1, false);
        dp[0] = true;

        int maxLen = 0;
        for(const string& word : wordDict){
            maxLen = max(maxLen, (int)word.length());
        }
for (int i = 1; i <= n; ++i) {
            // Check substrings s[j...i-1] ending at index i-1
            for (int j = i - 1; j >= max(0, i - maxLen); --j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Found a valid segmentation for s[0...i-1]
                }
            }
        }

        return dp[n];        
    }
};