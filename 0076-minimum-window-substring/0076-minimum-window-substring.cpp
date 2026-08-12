class Solution {
public:
    string minWindow(string s, string t) {
        // STEP 1: NEED MAP - Target characters ki frequency
        unordered_map<char, int> need;
        for(char c : t) {
            need[c]++;
        }
        
        // STEP 2: WINDOW MAP - Current window ki frequency
        unordered_map<char, int> window;
        
        int left = 0, right = 0;          // Window pointers
        int valid = 0;                    // Kitne unique characters match ho gaye
        int start = 0, minLen = INT_MAX;  // Answer track
        
        // STEP 3: EXPAND RIGHT
        while(right < s.length()) {
            char c = s[right];
            right++;
            
            // Agar character target me hai to window me add karo
            if(need.count(c)) {
                window[c]++;
                // Agar frequency match ho gayi to valid++
                if(window[c] == need[c]) {
                    valid++;
                }
            }
            
            // STEP 4: JAB VALID WINDOW MILE, SHRINK KARO
            while(valid == need.size()) {
                // Update answer
                if(right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                
                // Left side se character remove karo
                char d = s[left];
                left++;
                
                // Agar removed character target me tha
                if(need.count(d)) {
                    // Agar frequency match thi to valid--
                    if(window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        
        // STEP 5: RETURN RESULT
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};