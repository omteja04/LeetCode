class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMp;
        for (auto& ch : t) {
            tMp[ch]++;
        }
        int sl = s.length();
        int tl = t.length();
        string ans = "0";
        int len = INT_MAX, req = tMp.size(), formed = 0, start = 0;
        unordered_map<char, int> windowMap;
        int left = 0, right = 0;
        while (right < sl) {
            char ch = s[right];
            windowMap[ch]++;
            if (tMp.find(ch) != tMp.end() && tMp[ch] == windowMap[ch]) {
                formed++;
            }
            while (left <= right && formed == req) {
                char c = s[left];
                if (len > right - left + 1) {
                    len = right - left + 1;
                    start = left;
                }
                windowMap[c]--;
                if(windowMap[c] == 0) windowMap.erase(c);
                if (tMp.find(c) != tMp.end() && tMp[c] > windowMap[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};