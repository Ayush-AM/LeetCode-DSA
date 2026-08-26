class Solution {
public:
    void getSubsets(vector<int>&nums, vector<int>&ans, int i, vector<vector<int>> &sets ){
        if(i == nums.size()){
            sets.push_back(ans);
            return ;
        }


        ans.push_back(nums[i]);
        getSubsets(nums, ans, i+1, sets);
        ans.pop_back();

        int idx = i+1;
        while(idx<nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        getSubsets(nums, ans, idx, sets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> sets;
        sort(nums.begin(), nums.end());
        getSubsets(nums, ans, 0, sets);
        return sets;
    }
};