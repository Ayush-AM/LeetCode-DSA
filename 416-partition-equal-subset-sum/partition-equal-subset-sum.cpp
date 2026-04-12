class Solution {
public:     
    bool rec(int i, int sum, int totalSum, vector<int>& nums, vector<vector<int>>&dp){
        if(i==nums.size()){
            return sum == (totalSum/2);
        }

        if(dp[i][sum] != -1) return dp[i][sum];

        bool not_take = rec(i+1,sum, totalSum, nums, dp);
        bool take = rec(i+1,sum+nums[i],totalSum, nums, dp);

        return dp[i][sum] = not_take || take;
    }



    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto &it:nums){
            totalSum+=it;
        }
        if(totalSum%2 == 1) return false;

        vector<vector<int>>dp(nums.size()+1,vector<int>(totalSum+1,-1));
        return rec(0,0,totalSum,nums, dp);
    }
};