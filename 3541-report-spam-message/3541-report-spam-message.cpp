class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string>s;
        for(string i: bannedWords) {
            s.insert(i);
        }
        int cnt = 0;
        for(string k : message) {
            if(s.contains(k)) {
                cnt++;
            }
            if(cnt == 2) {
                return true;
            }
        }
        return false;
    }
};