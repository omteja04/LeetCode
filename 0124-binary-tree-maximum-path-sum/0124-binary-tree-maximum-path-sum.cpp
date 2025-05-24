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
    int maxi = INT_MIN;
    int help(TreeNode* root) {
        if(!root) return 0;
        int left = max(help(root->left), 0);
        int right = max(help(root->right), 0);
        int withRoot = root->val + left + right;
        maxi = max(maxi, withRoot);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return maxi;
    }
};