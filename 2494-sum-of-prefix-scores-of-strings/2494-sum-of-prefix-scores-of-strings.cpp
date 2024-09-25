struct Node{
    Node* links[26] = {nullptr};
    int prefixCnt = 0;
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void increasePrefix() {
        prefixCnt++;
    }
    int getPrefix() {
        return prefixCnt;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
    }
    int countWordsStartingWith(string &word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }
    Node* getRoot() {
        return root;
    }

};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto &word: words) {
            trie.insert(word);
        }
        vector<int>ans;
        for(auto word: words) {
            int cnt = 0;
            Node* node = trie.getRoot();
            for(char ch: word) {
                if(node->containsKey(ch)) {
                    node = node->get(ch);
                    cnt += node->getPrefix();
                } else{
                    break;
                }
            }
            
            ans.push_back(cnt);
        }
        return ans;



    }
};