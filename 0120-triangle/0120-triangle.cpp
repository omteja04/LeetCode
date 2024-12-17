class Solution {
public:
    int fun(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];

        if(i == (n - 1)) {
            return triangle[i][j];
        }

        int down = triangle[i][j] + fun(i + 1, j, triangle, n, dp);
        int diag = triangle[i][j] + fun(i + 1, j + 1, triangle, n, dp);

        int ans = min(down, diag);
        return dp[i][j] = ans;

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
	    return fun(0, 0, triangle, triangle.size(), dp);
    }
};