class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // string ans = "";

        // for(int i = 0; i < strs[0].size(); i++) {

        //     char ch = strs[0][i];

        //     for(int j = 1; j < strs.size(); j++) {

        //         // if current string ends
        //         // OR character mismatches
        //         if(i >= strs[j].size() || strs[j][i] != ch) {
        //             return ans;
        //         }
        //     }

        //     ans += ch;
        // }

        // return ans;
        string prefix = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];

        for(int i=0;i<first.size(); i++){
            if(first[i] == last[i]) prefix += first[i];
            else break;
        }
        return prefix;
    }
};