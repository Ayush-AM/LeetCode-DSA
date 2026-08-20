// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//         nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//         sort(nums1.begin(), nums1.end());

//         double sum = 0;
//         for(int i=0; i<nums1.size(); i++){
//             sum = sum + nums1[i];
//         }
//         double avg= 0;
//         avg = sum / nums1.size();
//         return avg;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. Merge the two arrays
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        // 2. Sort the combined array
        sort(nums1.begin(), nums1.end());
        
        int n = nums1.size();
        
        // 3. Find the median
        if (n % 2 == 1) {
            // If the total size is odd, return the middle element
            return nums1[n / 2];
        } else {
            // If the total size is even, return the average of the two middle elements
            return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
        }
    }
};