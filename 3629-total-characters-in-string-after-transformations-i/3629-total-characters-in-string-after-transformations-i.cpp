class Solution {
public:
    const int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        int ans = 0;
        while(t--) {
            vector<int> temp(26, 0);
            for(int i = 0; i < 25; i++) {
                temp[i + 1] =  freq[i]; 
            }
            temp[0] = (temp[0] + freq[25]) % MOD;
            temp[1] = (temp[1] + freq[25]) % MOD;

            freq = temp;
        }
        int sum = 0;
        for(auto &it: freq) {
            sum = (sum + it) %MOD;
        }
        return sum;
    }
};