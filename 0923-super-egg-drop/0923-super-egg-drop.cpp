class Solution {
public:
    int levi(int k, int n, vector<vector<int>>& dp) {
        if(k == 1) return n;
        if(n == 0 || n == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];

        int mini = INT_MAX;

        int low = 1;
        int high = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int eggBreak = levi(k - 1, mid - 1, dp);
            int notBreak = levi(k, n - mid, dp);
            int res = max(eggBreak, notBreak) + 1;
            mini = min(mini, res);
            if(eggBreak < notBreak) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return dp[k][n] = mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>( n + 1, -1));
        return levi(k , n, dp);
    }
};