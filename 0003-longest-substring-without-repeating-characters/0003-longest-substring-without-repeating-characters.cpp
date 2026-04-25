class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // lastPos vector banaya ASCII size (128) ka, 
        // isme hum store karenge ki kaunsa character aakhri baar kahan dikha tha.
        vector<int> lastPos(128, -1);
        int maxLength = 0; // Sabse bade substring ki length store karega
        int left = 0; // Sliding window ka left boundary pointer

        // Window ke 'right' boundary ko aage badhate jao
        for(int right =0; right<s.length(); right++){
            char current = s[right];

            // Agar ye character pehle dikh chuka hai AUR 
            // uska index current window (left) ke andar hai...
            if(lastPos[current] >= left){
            // ...toh left pointer ko purani position ke ek step aage jump karado
                left = lastPos[current]+1;
            }

            // Character ki nayi/updated position save kar lo
            lastPos[current] = right;
            // Window ki current size check karo aur agar badi hai toh maxLength update karo
            // Formula: (right index - left index + 1)
            maxLength = max(maxLength, right-left+1);

        }
        return maxLength;  // Final result return kar do
    }
};