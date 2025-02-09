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
    unordered_map<int, int> inorderMap;
    int preIndex = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderMap.clear();
        preIndex = 0;

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return solve(preorder, 0, inorder.size() - 1);
    }
    TreeNode* solve(vector<int> &preorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int nodeVal = preorder[preIndex++];
        TreeNode* node = new TreeNode(nodeVal);
        int mid = inorderMap[nodeVal];
        node->left = solve(preorder, left, mid - 1);
        node->right = solve(preorder, mid + 1, right);
        return node;
    }
};