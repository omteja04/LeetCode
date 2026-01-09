/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return nullptr;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        q.push(root);
        parent[root] = nullptr;
        vector<TreeNode*> lastLevel;
        while (!q.empty()) {
            lastLevel.clear();
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                lastLevel.push_back(node);
                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());
        while(deepest.size() > 1) {
            unordered_set<TreeNode*> parents;
            for(auto &node : deepest) {
                parents.insert(parent[node]);
            }
            deepest = parents;
        }
        return *deepest.begin();
    }
};