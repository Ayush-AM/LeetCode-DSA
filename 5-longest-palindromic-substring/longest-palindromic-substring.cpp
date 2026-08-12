class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start =0, maxLen = 1;
        for (int i=0;i<s.size();i++){
            int left = i;
            int right = i;
            while(left>=0 && s[left] == s[right] && right<s.size() ){
                if(right-left+1 > maxLen){
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            left = i;
            right = i+1;
            while(left>=0 && s[left] == s[right] && right<s.size() ){
                if(right-left+1 > maxLen){
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLen);
    }
};