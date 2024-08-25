class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        int j = 0;
        for(int i = 1; i < n; i++) {
            while(j < i) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                j++;
            }
            j = 0;
        }
        return *max_element(dp.begin(), dp.end());
    }
};