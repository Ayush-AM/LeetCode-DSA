class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int mid = 0;
        int hi = nums.size() - 1;

        while (mid <= hi) {
            switch (nums[mid]) {
                // If the element is 0, group it at the beginning
                case 0:
                    swap(nums[lo++], nums[mid++]);
                    break;
                
                // If the element is 1, it's already in the right middle zone
                case 1:
                    mid++;
                    break;
                
                // If the element is 2, group it at the end
                case 2:
                    swap(nums[mid], nums[hi--]); // Fixed: Decrement hi to narrow down the boundary
                    break;
            }
        }
    }
};