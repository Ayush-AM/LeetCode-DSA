class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int slow = 0;
        // for(int fast=1; fast<nums.size(); fast++){
        //     if(nums[fast] != nums[slow]){
        //         nums[slow]=nums[fast];
        //         slow++;
        //     }
        // }
        // return slow++;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};