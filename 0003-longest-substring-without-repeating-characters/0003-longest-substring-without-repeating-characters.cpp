class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        unordered_set<char> st;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            while(st.count(s[i])) {
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            ans = max(ans, i - j + 1);
            // cout<< ans <<" ";

        }
        return ans;
        
    }
};