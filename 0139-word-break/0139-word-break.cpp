struct Node {
    
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node *node = root;
        for (char &ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string &word, int start, int end) {
        Node *node = root;
        for (int i = start; i < end; i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
         for(auto &word : wordDict) {
            trie.insert(word);
        }
        int n = s.size();
        vector<bool>dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j  = 0; j < i; j++) {
                if (dp[j] && trie.search(s, j, i)) {
                    dp[i] = true;
                    break; 
                }
            }
        }
        return dp[n];
    }
};