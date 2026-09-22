class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        // Start from day 1 and compare with the previous day
        for(int i = 1; i < prices.size(); i++){
            // If the price went up, add the difference to our total profit
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};