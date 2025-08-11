const int MOD = 1e9 + 7;
using ll = long long;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> powers;
        for(int i = 0; i < 32; i++) {
            if(n & (1 << i))
                powers.push_back(1 << i);
        }
        vector<int> ans;
        for(auto &it : queries) {
            ll temp = 1;
            for(int i = it[0]; i <= it[1]; i++) {
                temp *= powers[i];
                temp %= MOD;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};