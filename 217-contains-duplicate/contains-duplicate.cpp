class Solution {
public:
    //her we have 3 ways
    bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for(int i=0; i<nums.size(); i++){ // int num:nums
        if(seen.count(nums[i])){ //here we calculate count of i
            return true;
        }
        seen.insert(nums[i]);
    }       
    return false;
    }

    /* // this is sorting approach
     bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
    */
};