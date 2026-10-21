#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // 0 operations if already sorted
        if (is_sorted(s.begin(), s.end())) return 0;
        
        // Impossible to sort if length is 2 and unsorted
        if (n == 2) return -1;
        
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());
        
        // 1 operation: min_char at index 0 (sort suffix) OR max_char at index n-1 (sort prefix)
        if (s[0] == min_char || s[n - 1] == max_char) return 1;
        
        // 2 operations: min_char or max_char exists in the inner substring s[1...n-2]
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == min_char || s[i] == max_char) return 2;
        }
        
        // 3 operations: max_char is at s[0] and min_char is at s[n-1] with no extrema inside
        return 3;
    }
};