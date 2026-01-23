class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int len = beginWord.size();
        while (!q.empty()) {
            auto [str, cnt] = q.front();
            cout << str << " " << cnt << "\n";
            if (str == endWord)
                return cnt;
            q.pop();
            for (int i = 0; i < len; i++) {
                string copy = str;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if(ch == str[i]) continue;
                    copy[i] = ch;
                    if (st.count(copy)) {
                        q.push({copy, cnt + 1});
                        st.erase(copy);
                    }
                }
            }
        }
        return 0;
    }
};