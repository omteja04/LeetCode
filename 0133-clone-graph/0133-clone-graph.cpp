/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> originalToClone;
    Node* dfs(Node* originalNode) {
        if(originalToClone.contains(originalNode)) {
            return originalToClone[originalNode];
        }
        Node* clone = new Node(originalNode->val);
        originalToClone[originalNode] = clone;
        for(Node* neighbour : originalNode -> neighbors) {
            clone->neighbors.push_back(dfs(neighbour));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }
};