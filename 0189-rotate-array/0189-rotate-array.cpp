class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k >= n
        if (k == 0) return;

        // 1. Store the last k elements into a temporary vector
        vector<int> temp(nums.end() - k, nums.end());

        // 2. Shift the remaining elements from the front to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // 3. Copy the temp elements back to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};