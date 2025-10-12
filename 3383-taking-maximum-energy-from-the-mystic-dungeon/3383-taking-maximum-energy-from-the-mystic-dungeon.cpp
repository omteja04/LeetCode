class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                dp[i] = energy[i] + dp[i + k];
            } else {
                dp[i] = energy[i];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};