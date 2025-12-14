const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> pos;
        for(int i = 0; i < corridor.size(); i++) {
            if(corridor[i] == 'S') pos.push_back(i);
        }
        if(pos.size() % 2 != 0 || pos.empty()) return 0;
        long long ans = 1;
        for (int i = 2; i < pos.size(); i += 2) {
            int gap = pos[i] - pos[i - 1];
            ans = (ans * gap) % MOD;
        }
        return ans;



    }
};