class Solution {
public:
    int sumCounts(vector<int>& nums) {
    vector<vector<int>> allSubarrays;
    int n = nums.size();
    int square = 0;

    // Pick starting point
    for (int i = 0; i < n; i++) {
        // Pick ending point
        for (int j = i; j < n; j++) {
            // Extract the subarray from index i to j
            vector<int> subarray(nums.begin() + i, nums.begin() + j + 1);
            unordered_set<int> distinctElements(subarray.begin(), subarray.end());
            int count = distinctElements.size();
            square += count * count;
        }
    }
    
    return square;
    }
};