class Node{
    private: 
        Node* links[26];
        bool isEnd;
    public:
        Node() {
            for(int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            isEnd = false;
        }
        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }
        void setEnd() {
            isEnd = true;
        }
        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }
        Node* get(char ch) {
            return links[ch - 'a'];
        }
        
        
};
class Trie{
    private:
        Node* root = new Node();
    public:
        void insert( string &word) {
            Node* node = root;
            for(int i = 0; i  <word.size();i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        int getPrefixLength(string &word) {
            Node* node = root;
            int res = 0;
            for(char ch : word) {
                if(!node->containsKey(ch)) {
                    break;
                }
                node = node->get(ch);
                res++;
            }
            return res;
        }
        ~Trie() {
            delete root;
        }

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        trie.insert(strs[0]);
        int ans = strs[0].length();
        for(string &word : strs) {
            int temp = trie.getPrefixLength(word);
            ans = min(ans, temp);
        }
        return strs[0].substr(0, ans);
    }
};