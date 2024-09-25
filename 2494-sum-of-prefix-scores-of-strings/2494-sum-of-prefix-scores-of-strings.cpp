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
    int cntPrefixScore(string &word) {
        int cnt = 0;
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                break;
            }
            node = node->get(word[i]);
            cnt += node->getPrefix();
            
        }
        return cnt;
    }

};
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto &word: words) {
            trie.insert(word);
        }
        vector<int>ans;
        
        for(string &word: words){    
            ans.push_back(trie.cntPrefixScore(word));
        }
        return ans;



    }
};