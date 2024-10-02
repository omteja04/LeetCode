/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        auto[leftWithoutRobbing, leftWithRobbing] = dfs(root->left);
        auto[rightWithoutRobbing, rightWithRobbing] = dfs(root->right);

        int withoutRobbing = max(leftWithoutRobbing, leftWithRobbing) + max(rightWithoutRobbing, rightWithRobbing);
        
        int withRobbing = root->val + leftWithoutRobbing + rightWithoutRobbing;

        return {withoutRobbing, withRobbing};
    }
};
