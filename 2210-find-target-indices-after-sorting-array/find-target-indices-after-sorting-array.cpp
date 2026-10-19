class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Sort the original array completely first
        sort(nums.begin(), nums.end());

        vector<int> newArr;

        // Loop through and collect all indices where target appears
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                newArr.push_back(i); // store index i, not the value nums[i]
            }
        }

        return newArr;
    }
};