class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int amt = 0; amt <= amount; amt++) {
            for (int i = 0; i < n; i++) {
                if (amt - coins[i] >= 0 && dp[amt - coins[i]] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt - coins[i]] + 1);
                }
            }
        }
        return (dp[amount] != INT_MAX ? dp[amount] : -1);
    }
};