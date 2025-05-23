class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>mp;
        int n = s.size();
        int left = 0;
        int cnt = 0;
        for(int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            while(mp.size() == 3) {
                cnt += (n - right);
                mp[s[left]]--;
                if(mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return cnt;
    }
};