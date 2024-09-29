class Node{
private:
    Node *links[26];
    bool flag;
public:
    Node() {
        flag = false;
        for(int i = 0; i < 26; i++) links[i] = nullptr;
    }
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
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

private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch :word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word, Node* node, int index = 0) {
        int n = word.length();
        if(n == index) return node->isEnd();
        for(int i = index; i < n; i++) {
            if(word[i] == '.') {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(node->containsKey(ch)) {
                        if(search(word, node->get(ch), index + 1)) {
                            return true;
                        }  
                    }
                }
                return false;
            }else {
                if(!node->containsKey(word[i])) {
                    return false;
                }
                return  search(word, node->get(word[i]), index + 1);
            }
        }
        return node->isEnd();
    }
    Node* getRoot() {
        return root;
    }
};
class WordDictionary {
private:
    Trie* node;
public:
    WordDictionary() {
        node = new Trie();
    }
    
    void addWord(string word) {
       node->insert(word);
    }
    
    bool search(string word) {
        return node->search(word, node->getRoot());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */