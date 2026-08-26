// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         int totalSubsets = 1 << n; 
//         vector<vector<int>> result;
//         for (int i = 0; i < totalSubsets; ++i) {
//             vector<int> currentSubset;
//             for (int j = 0; j < n; ++j) {
//                 if ((i & (1 << j)) != 0) {
//                     currentSubset.push_back(nums[j]);
//                 }
//             }
//             result.push_back(currentSubset);
//         }
        
//         return result;            
//     }
// };

class Solution {
public:
    void getSubsets(vector<int>&nums, vector<int>&ans, int i, vector<vector<int>> &sets ){
        if(i == nums.size()){
            sets.push_back({ans});
            return ;
        }

        ans.push_back(nums[i]);
        getSubsets(nums, ans, i+1, sets);
        ans.pop_back();
        getSubsets(nums, ans, i+1, sets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> ans; 
        getSubsets(nums, ans, 0, sets);
        return sets;
    }

};