class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int iWillBuy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int iWillSell = prices[i];
            profit = max(profit, iWillSell - iWillBuy);
            iWillBuy = min(iWillSell, iWillBuy);
        }
        return profit;
    }
};