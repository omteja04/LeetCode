class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i >= m || j >= n) {
            return INT_MAX;
        }
        if(i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = INT_MAX;
        if(j + 1 < n) {
            res = solve(i, j + 1, grid, dp);
        }
        if(i + 1 < m) {
            res = min(res, solve(i + 1, j, grid, dp));
        }
        res += grid[i][j];

        return dp[i][j] = res;
    }
     int minPathSum(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(0, 0, grid, dp);
    }
};