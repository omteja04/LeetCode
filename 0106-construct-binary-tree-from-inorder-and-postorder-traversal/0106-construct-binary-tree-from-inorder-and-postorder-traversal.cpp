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
    int postIndex;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorderMap.clear();
        postIndex = postorder.size() - 1;

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return solve(postorder, 0, inorder.size() - 1);
    }
    TreeNode* solve(vector<int> &postorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int nodeVal = postorder[postIndex--];
        TreeNode* node = new TreeNode(nodeVal);
        int mid = inorderMap[nodeVal];
        node->right = solve(postorder, mid + 1, right);
        node->left = solve(postorder, left, mid - 1);
        return node;
    }
};