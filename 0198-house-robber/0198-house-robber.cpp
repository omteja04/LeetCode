class Solution {
public:
    int fun(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0) {
            return nums[ind];
        }
        if (ind < 0) {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        int pick = nums[ind] + fun(ind - 2, nums, dp);
        int notPick = fun(ind - 1, nums, dp);
        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int nonPick = dp[i - 1];
            dp[i] = max(pick, nonPick);
        }
        return dp[n - 1];
    }
};