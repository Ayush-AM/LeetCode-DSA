class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Shift to 0-indexed to handle the 1-26 mapping cleanly
            columnNumber--; 
            
            // Get the current character
            char remainderChar = 'A' + (columnNumber % 26);
            result += remainderChar;
            
            // Move to the next position
            columnNumber /= 26;
        }
        
        // The characters are collected from right to left, so reverse the string
        reverse(result.begin(), result.end());
        return result;
    }
};