class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        // int j = 0;
        for(int i = 1; i < word.size(); i++) {
            if(word[i] == word[i - 1]) cnt++;
        }
        return cnt;
    }
};