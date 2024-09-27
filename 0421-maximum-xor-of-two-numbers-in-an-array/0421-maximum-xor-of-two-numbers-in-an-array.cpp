struct Node{
    Node* links[2];
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};
class Trie{
    private: Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insert(int num) {
            Node* node = root;
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)) {
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMax(int x) {
            Node* node = root;
            int maxNum = 0;
            for(int i = 31; i >= 0; i--) {
                int bit = (x >> i) & 1;
                if(!node->containsKey(1 - bit)) {
                    node = node->get(bit);
                } else {
                    maxNum |= (1 << i);
                    node = node->get(1 - bit);
                }
            }
            return maxNum;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int &it : nums) {
            trie.insert(it);
        }
        int maxi = 0;
        for (int &it : nums) {
            maxi = max(maxi, trie.getMax(it));
        }
        return maxi;
    }
};