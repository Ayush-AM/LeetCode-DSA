// class Solution {
// public:

//     int rec(vector<int> &dp, int n){
//         if(n == 0 || n==1 || n==2 || n==3) return n;

//         if(dp[n] != -1){return dp[n];}

//         return dp[n] = rec(dp, n-1) + rec(dp, n-2);
//     }

//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return rec(dp, n);
//     }
// };

class Solution {
public:


    int climbStairs(int n) {
        if(n == 0 || n==1 || n==2 || n==3) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};