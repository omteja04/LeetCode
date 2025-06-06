class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto &ch : s) {
            mp[ch]++;
        }
        for(auto &ch : t) {
            mp[ch]--;
        }
        for(auto &it : mp) {
            if(it.second != 0) return false;
        }
        return true;
    }
};