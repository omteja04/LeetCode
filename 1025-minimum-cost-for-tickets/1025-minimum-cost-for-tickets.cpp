class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int oneDayPass = INT_MAX, sevenDayPass = INT_MAX, thirtyDayPass = INT_MAX;
        int maxi = *max_element(days.begin(), days.end());
        vector<int> dp(maxi + 1, 0);
        unordered_set<int>st(days.begin(), days.end());
        for(int i = 1; i <= maxi; i++) {
            if(st.count(i)) {
                    oneDayPass = dp[i - 1] + cost[0];
                    sevenDayPass = dp[max(0, i - 7)] + cost[1];
                    thirtyDayPass = dp[max(0, i - 30)] + cost[2];
                dp[i] = min({oneDayPass, sevenDayPass, thirtyDayPass});
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[maxi];
    }
};