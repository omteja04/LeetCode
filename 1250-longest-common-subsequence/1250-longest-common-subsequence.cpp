class Solution {
public:
    int longestCommonSubsequence(string str, string str2) {
        int m = str.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (str[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[m][n];
    }
};