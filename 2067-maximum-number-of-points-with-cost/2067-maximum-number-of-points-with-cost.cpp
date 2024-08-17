class Solution {
public:
    int r, c;
    vector<vector<long long>> dp;
    // long long rec(vector<vector<int>>& points, int row, int column) {
    //     if(row == 0) {
    //         int ans = 0;
    //         for(int i = 0; i < c; i++) {
    //             ans = max(ans, (points[0][i] - abs(column - i)));
    //         }
    //         return dp[row][column] = ans;
    //     }
    //     if(dp[row][column] != -1) {
    //         return dp[row][column];
    //     }
    //     long long maxi = 0;
    //     for(int i = 0 ; i < c; i++) {
    //         maxi = max(maxi, rec(points, row - 1, i) + points[row][i] - abs(column - i));
    //     }
    //     return dp[row][column] = maxi;
    // }
    

    long long maxPoints(vector<vector<int>>& points) {
        r = points.size();
        c = points[0].size();
        dp.assign(r, vector<long long>(c, -1));
        long long ans = 0;
        for(int i = 0 ; i < c; i++) {
            dp[0][i] = points[0][i];
            ans = max<long long int>(ans, dp[0][i]);
        }
        for(int i = 1; i < r; i ++) {
            vector<long long int> leftMax(c,0);
            vector<long long int> rightMax(c,0);

            leftMax[0] = dp[i - 1][0];
            for(int x = 1; x < c ; x++) {
                leftMax[x] = max(leftMax[x - 1] - 1, dp[i-1][x]);
            }
            rightMax[c - 1] = dp[i - 1][c - 1];
            for(int x = c - 2; x >= 0 ; x--) {
                rightMax[x] = max(rightMax[x + 1] - 1, dp[i - 1][x]);
            }

            for(int j = 0 ; j < c; j++) {
                dp[i][j] = max(rightMax[j] , leftMax[j]) + points[i][j];
            }
        }
        ans = 0;
        for(int i = 0 ; i < c; i++) {
            ans = max<long long int>(ans, dp[r - 1][i]);
        }
        return ans;


    }
};