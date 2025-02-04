class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a, b = INT_MAX, c = INT_MAX;
                a = dp[i - 1][j];
                if (j > 0)
                    b = dp[i - 1][j - 1];
                if (j < n - 1)
                    c = dp[i - 1][j + 1];
                dp[i][j] = matrix[i][j] + min({a, b, c});
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};