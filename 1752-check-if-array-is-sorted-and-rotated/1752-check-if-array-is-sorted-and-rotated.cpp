class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Using % n seamlessly checks the next element, 
            // including wrapping the last element back to index 0
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // Optimization: If we find more than 1 drop, it's definitely false
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};