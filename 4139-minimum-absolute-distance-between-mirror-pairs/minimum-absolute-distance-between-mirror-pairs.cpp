class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = INT_MAX;
        unordered_map<int, int> mp;

        for(int j=0; j<n; j++){
            if (mp.count(nums[j])){
                min_dist = min(min_dist, j - mp[nums[j]]);
            }

            int reversed_val = reverseInt(nums[j]);
            mp[reversed_val] = j;
        }
        return (min_dist == INT_MAX) ? -1:min_dist;
    }


private:
    int reverseInt(int n){
        long rev = 0;
        while (n>0){
            rev = rev*10+(n%10);
            n/=10;
        }
        return (int)rev;
    }
};


