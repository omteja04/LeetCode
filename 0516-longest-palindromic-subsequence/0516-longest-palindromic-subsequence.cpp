class Solution {
public:
    int func(int i, int j, string &s1,string &s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int l = 0, r = 0;
        if(s1[i] == s2[j]) {
            l = 1 + func(i - 1, j - 1, s1, s2, dp);
        } else {
            r = max(func(i - 1, j, s1, s2, dp), func(i, j - 1, s1, s2, dp));
        }
        return dp[i][j] = max(l, r);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string revS = s;
        reverse(revS.begin(), revS.end());
        return func(n - 1, n - 1, s, revS, dp);
    }
};