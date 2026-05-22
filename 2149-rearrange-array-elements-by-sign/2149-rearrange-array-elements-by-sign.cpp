#include <vector>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        
        int posIdx = 0;
        int negIdx = 1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIdx] = nums[i];
                posIdx += 2;
            } else {
                ans[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        
        return ans;
    }
};