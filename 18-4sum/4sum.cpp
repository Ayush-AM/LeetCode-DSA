class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // A quadruplet requires at least 4 elements
        if (n < 4) return result;

        // Step 1: Sort to manage duplicates and enable two pointers
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first two numbers
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 3: Two pointers for the remaining two elements
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to prevent overflow since nums[i] can be 10^9
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++; // Increase sum
                    } 
                    else {
                        right--; // Decrease sum
                    }
                }
            }
        }

        return result;
    }
};