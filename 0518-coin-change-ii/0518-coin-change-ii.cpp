class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount + 1, 0LL);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int x = coins[i]; x <= amount; x++) {
                if (x >= coins[i]) {
                    dp[x] = dp[x] + dp[x - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};