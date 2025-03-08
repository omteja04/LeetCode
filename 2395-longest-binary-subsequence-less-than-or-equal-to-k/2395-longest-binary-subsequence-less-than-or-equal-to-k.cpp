class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeros = 0;
        for(char &ch : s) {
            if(ch == '0') zeros++;
        }
        int maxLen = 0;
        int numberObtained = 0;
        int c = 1;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(numberObtained + c > k) {
                break;
            }
            if(s[i] == '1') {
                numberObtained += c;
            } else {
                zeros--;
            }
            c *= 2;
            maxLen++;
        }
        return maxLen + zeros;
    }
};