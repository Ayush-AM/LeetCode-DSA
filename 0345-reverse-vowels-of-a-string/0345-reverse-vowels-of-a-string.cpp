class Solution {
public:
    // A simple function that returns true if a character is a vowel
    bool isVowel(char c) {
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }

    string reverseVowels(string s) {
        string collectedVowels = "";
        
        // Step 1: Collect all vowels from the string
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                collectedVowels.push_back(s[i]);
            }
        }
        
        // Step 2: Put them back in reverse order
        int index = collectedVowels.length() - 1; 
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = collectedVowels[index];
                index--;
            }
        }
        
        return s;
    }
};