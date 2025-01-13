class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        map<char,int>mp;
        for(char &ch:s) {
            mp[ch]++;
        }
        int cnt = 0;
        for(auto &pair : mp) {
            if(pair.second > 2) {
                if(pair.second % 2 == 0) {
                    cnt = cnt + pair.second - 2;
                    pair.second = 2;
                } else {
                    cnt = cnt + pair.second - 1;
                    pair.second = 1;
                }

            }
        }
        return n - cnt;
    }
};