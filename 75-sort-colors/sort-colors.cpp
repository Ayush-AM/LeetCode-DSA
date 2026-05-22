class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int medium=0;
        int high=nums.size()-1;
        while(medium<=high){
            if(nums[medium]==0){
                swap(nums[low],nums[medium]);
                low++,medium++;
            }
            else if(nums[medium]==1){
                medium++;
            }
            else{
                swap(nums[medium],nums[high]);
                high--;
            }
        }

    }
};