class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> people(41);
        for(int person = 0; person < n; person++) {
            for(auto &hat: hats[person]) {
                people[hat].push_back(person);
            }
        }
        vector<vector<int>>dp(41, vector<int>(1 << n));
        dp[0][0] = 1;

        for(int hat = 1; hat <= 40; hat++) {
            for(int mask = 0; mask < (1 << n); mask++) {
                // not choosing the current hat
                dp[hat][mask] = dp[hat - 1][mask];
                
                for(auto & person: people[hat]) {
                    if(((mask >> person) & 1) == 0) continue;
                    dp[hat][mask] += dp[hat - 1][mask - (1 << person)];
                    dp[hat][mask] %= MOD;
                }

            }
        }
        return dp[40][(1 << n) - 1];
    }
};