class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int minProfit = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            minProfit = min(minProfit, prices[i]);
            maxi = max(maxi, prices[i] - minProfit);
        }
        return maxi;
    }
};