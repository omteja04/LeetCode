class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>mySet;
        for(auto &num : arr1) {
            string s = to_string(num);
            for(int i = 1 ; i <= s.length(); i++) {
                mySet.insert(s.substr(0,i));
            }
        }
        int cnt = 0;
        for(auto& num : arr2) {
            string s = to_string(num);
            for(int i = 1 ; i <= s.length(); i++) {
                string str = s.substr(0, i);
                if(mySet.contains(s.substr(0, i))) {
                    int len = str.length();
                    cnt = max(cnt, len);
                }
            }
        }
        return cnt;
    }
};