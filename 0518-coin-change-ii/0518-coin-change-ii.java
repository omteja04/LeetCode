class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int i = 0; i < coins.length; i++) {
            for (int x = 1; x <= amount; x++) {
                if (x >= coins[i]) {
                    dp[x] = dp[x] + dp[x - coins[i]];
                }
            }
        }
        return dp[amount];
    }
}