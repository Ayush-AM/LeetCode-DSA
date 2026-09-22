class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int elem;

        for(int i=0; i<nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                elem = nums[i];
            }
            else if(elem == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return elem;
    }
};

/*
        int n = nums.size();
        for(int val : nums){
            int freq=0;
            for(int el : nums){
                if(el == val){
                    freq++;
                }
            }
            if(freq > n/2){
                return val;
            }

        }
        return -1;
*/