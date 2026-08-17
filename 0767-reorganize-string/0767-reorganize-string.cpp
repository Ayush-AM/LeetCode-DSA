class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        int maxFreq = 0;
        for (auto& [c, count] : freq) {
            maxFreq = max(maxFreq, count);
        }
        if (maxFreq > (s.length() + 1) / 2) return "";
        
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [c, count] : freq) {
            maxHeap.push({count, c});
        }
        
        string result = "";
        pair<int, char> prev = {-1, '#'};
        
        while (!maxHeap.empty()) {
            auto [count, c] = maxHeap.top();
            maxHeap.pop();
            
            result += c;
            
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            
            prev = {count - 1, c};
        }
        
        return result;
    }
};