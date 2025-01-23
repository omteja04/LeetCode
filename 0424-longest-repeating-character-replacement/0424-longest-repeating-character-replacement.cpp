class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.length();
        int ans = 0;
        for(int left = 0, right = 0; right < n; right++) {
            freq[s[right] - 'A']++;
            int maxFreq = *max_element(freq.begin(), freq.end());
            int rem = right - left + 1 - maxFreq;
            if(rem > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};