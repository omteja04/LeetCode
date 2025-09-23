class Solution {
public:
    int solve(int l, int r, vector<int> &rod, vector<vector<int>> &dp) {
        if(l > r) return INT_MAX;
        if(l + 1 == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for(int p = l + 1; p <= r - 1; p++) {
            ans = min(ans, rod[r] - rod[l] + solve(l, p, rod, dp) + solve(p, r, rod, dp));
        }
        return dp[l][r] = ans;
        

    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int>rod;
        rod.push_back(0);
        for(auto x:cuts){
            rod.push_back(x);
        }
        rod.push_back(n);
        int m=rod.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return solve(0, m - 1, rod, dp);
    }
};