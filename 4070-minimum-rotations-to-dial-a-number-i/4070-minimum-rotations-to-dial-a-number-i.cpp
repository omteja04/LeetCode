class Solution {
public:
    int minRotations(string s) {
        int from = 0, to = 0;
        int ans = 0;
        for(auto &ch : s) {
            to = ch - '0';
            // int onePossibility = from ??
            ans += min(abs(to - from), 10 - abs(to - from));
            from = to;
        }
        return ans;
    }
};