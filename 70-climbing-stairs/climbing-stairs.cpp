class Solution {
public:

    int rec(vector<int> &dp, int n){
        if(n == 0 || n==1 || n==2 || n==3) return n;

        if(dp[n] != -1){return dp[n];}

        return dp[n] = rec(dp, n-1) + rec(dp, n-2);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(dp, n);
    }
};