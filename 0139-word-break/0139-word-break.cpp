class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto &word : wordDict) {
            st.insert(word);
        }
        int n = s.size();
        vector<bool>dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j  = 0; j < i; j++) {
                if(dp[j] == true) {
                    string str = s.substr(j,  i - j);
                    if(st.contains(str)) {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};