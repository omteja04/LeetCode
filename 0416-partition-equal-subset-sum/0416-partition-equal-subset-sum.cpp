class Solution {
public:
    bool solve(vector<int> &nums, int target) {
        vector<bool>dp(target + 1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            for(int k = target; k >= nums[i]; k--) {
                dp[k] = dp[k] || dp[k - nums[i]];
            }
        }
        return dp[target];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)  return false;
        int k = sum / 2;
        return solve(nums,k);
    }
};