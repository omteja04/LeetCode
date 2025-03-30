class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            int endOfChar = mp[s[i]];
            end = max(end, endOfChar);
            if(i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};