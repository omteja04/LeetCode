class Solution {
public:
    string rabinKarp(string &s, int m) {
        if(m == 0) return "";
        int d = 256, mod = 1e9+7, n = s.size();
        long long powD = 1;
        for(int i = 0; i < m - 1; i++) {
            powD = (powD * d) % mod;
        }
        long long hash = 0;
        for(int i = 0; i < m; i++) {
            hash = (hash * d + s[i]) % mod;
        }
        unordered_map<int, vector<int>>mp;
        mp[hash] = {0}; // started at 0th index
        for(int i = 1; i <= n - m;i++) {
            hash = (1LL * d * ((hash - s[i - 1] * powD % mod + mod)) % mod + s[i + m - 1]) % mod;
            if(mp.find(hash) != mp.end()) {
                for(auto &j : mp[hash]) {
                    if(s.substr(i, m) == s.substr(j, m)) return s.substr(i, m);
                }
            }
            mp[hash].push_back(i);
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int left = 1;
        int right = s.length() - 1;
        string ans = "";
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            string t = rabinKarp(s, mid);
            if(t.size() > ans.size()) {
                ans = t;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};