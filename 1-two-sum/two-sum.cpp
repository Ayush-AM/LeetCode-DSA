class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[j] + nums[i] == target ) {
        //             return {i, j};
        //         }
        //     }
        // }
        // Return an empty vector if no solution is found

    unordered_map<int, int> m;

    for(int i = 0; i < nums.size(); i++) {

        int complement = target - nums[i];

        if(m.find(complement) != m.end()) {

            return {m[complement], i};
        }

        m[nums[i]] = i;
    }

    return {-1, -1};
    }
};