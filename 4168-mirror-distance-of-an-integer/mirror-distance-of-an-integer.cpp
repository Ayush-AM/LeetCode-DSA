class Solution {
public:
    int mirrorDistance(int n) {
        long long original = n;
        long long reversed = 0;
        long long temp = n;

        while(temp>0){
            reversed = reversed * 10 + (temp%10);
            temp /= 10;
        }
        return abs(original - reversed);
    }
};