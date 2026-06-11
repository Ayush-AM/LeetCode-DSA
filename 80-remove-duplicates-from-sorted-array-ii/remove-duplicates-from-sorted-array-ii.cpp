class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array has 2 or fewer elements, it's already valid.
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        // 'i' points to the index where the next valid element will be placed.
        int i = 2; 
        
        // Start iterating from the 3rd element (index 2)
        for (int j = 2; j < nums.size(); j++) {
            // Check if current element is different from the element 2 places behind 'i'
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++; // Move the valid pointer forward
            }
        }
        
        // 'i' represents the count of valid elements
        return i;
    }
};