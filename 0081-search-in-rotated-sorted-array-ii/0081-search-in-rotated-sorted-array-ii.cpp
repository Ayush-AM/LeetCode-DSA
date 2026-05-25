class Solution {
public:
    bool search(vector<int>& nums, int k) {
      int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If mid points to the target
        if (nums[mid] == k) return true;

        // Edge case: all three are equal, we cannot determine which side is sorted
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // If the left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= k && k <= nums[mid]) {
                high = mid - 1; // Target lies in left
            } else {
                low = mid + 1;  // Target lies in right
            }
        } else {
            // Right half is sorted
            if (nums[mid] <= k && k <= nums[high]) {
                low = mid + 1;  // Target lies in right
            } else {
                high = mid - 1; // Target lies in left
            }
        }
    }

    return false;  
    }
};