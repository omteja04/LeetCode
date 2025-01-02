class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        string vowel = "aeiou";
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            int strLen = words[i].length();
            if(vowel.find(words[i][0]) != string::npos && vowel.find(words[i][strLen - 1]) != string::npos) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }
        vector<int> res;
        for(auto &query : queries) {
            int x = query[0];
            int y = query[1];
            res.push_back(prefix[y + 1] - prefix[x]);
        }
        return res;
    }
};