/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int>res;
        for(int level = 0; !q.empty(); level++) {
            int size = q.size();
            res.push_back(INT_MIN);
            for(int i = 0; i  < size; i++) {
                auto front = q.front();
                q.pop();
                res[level] = max(res[level], front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            } 
            // TreeNode = q.top();
        }
        return res;

    }
};