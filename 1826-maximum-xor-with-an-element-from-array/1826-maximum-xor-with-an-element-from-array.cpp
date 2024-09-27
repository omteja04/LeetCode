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
struct oQ{
    int xi;
    int mi;
    int qInd;
    bool operator<(const oQ& other) const {
        return mi < other.mi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // oQ -> offlineQueries;
        // An offline algorithm allows us to manipulate the data to be queried before any answer is printed.
        // This is usually only possible when the queries do not update the original element set before printing the result.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<oQ> qs(q);
        for(int i = 0; i < q; i++) {
            qs[i].xi = queries[i][0];
            qs[i].mi = queries[i][1];
            qs[i].qInd = i;
        }
        int ind = 0;
        sort(qs.begin(), qs.end());
        Trie trie;
        vector<int>ans(q, 0);
        for(int i = 0; i < q; i++) {
            while(ind < n && qs[i].mi >= nums[ind]) {
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) ans[qs[i].qInd] = -1;
            else ans[qs[i].qInd] = trie.getMax(qs[i].xi);
        }
        return ans;



        
    }
};