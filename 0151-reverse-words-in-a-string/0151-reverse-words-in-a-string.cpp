class Solution {
public:
   string reverseWords(string s) {
    // int n = s.length();
    // string ans = "";
    // reverse(s.begin(), s.end());
    // for(int i = 0; i<n; i++){
    //     string word = "";
    //     while(i < n && s[i] != ' ') {
    //         word += s[i];
    //         i++;
    //     }
    //     reverse(word.begin(), word.end());
    //     if (word.length() > 0) {
    //         ans += " " + word;
    //     }
    // }
    // return ans.substr(1);

    vector<string> words;
    string w = "";

    for(char ch: s){
        if(ch!=' '){
            w += ch;
        }else if(!w.empty()){
            words.push_back(w);
            w = "";
        }
    }
    if(!w.empty()){
        words.push_back(w);
    }
    reverse(words.begin(), words.end());
    string ans = "";

    for(int i = 0; i<words.size(); i++){
        ans += words[i];
        if(i != words.size()-1) ans += " ";
    }
    return ans;
  }
};