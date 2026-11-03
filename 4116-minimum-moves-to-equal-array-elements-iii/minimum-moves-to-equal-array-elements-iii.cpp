class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max_val = nums.back(); // The target value all numbers must reach
        int left = 0;
        int right = nums.size() - 1; // Fixed: valid last index
        int moves = 0;
        
        // Two pointers moving inward, accumulating operations needed to reach max_val
        while (left <= right) {
            if (left == right) {
                moves += max_val - nums[left];
            } else {
                moves += (max_val - nums[left]) + (max_val - nums[right]);
            }
            left++;
            right--;
        }
        
        return moves;
    }
};