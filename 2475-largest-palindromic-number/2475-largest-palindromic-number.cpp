class Solution {
public:
    string largestPalindromic(string num) {
        string ans = "";
        vector<int> freq(10, 0);
        for(auto &ch : num) freq[ch - '0']++;
        int singleMax = -1;
        for(int  i = 9; i >= 0; i--) {
            int cnt = freq[i];
            if(cnt == 0) continue;
            if(ans.empty() && i == 0)  continue;
            if(cnt == 1) {
                singleMax = max(singleMax, i);
                continue;
            } else if(cnt >= 2) {
                for(int j = 1; j <= cnt / 2; j++) {
                    ans += (char) i + '0';
                }
                if(cnt % 2 != 0) {
                    singleMax = max(singleMax, i);
                }
            }
        }
        int leftLen = ans.length();
        if(singleMax != -1) {
            ans += (char) singleMax + '0';
        }
        for(int i = leftLen - 1; i >= 0; i--) {
            ans += ans[i];
        }
        return ans.empty() ? "0" : ans; 
    }
};