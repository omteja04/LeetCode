/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParents(TreeNode* root, unordered_map<TreeNode* , TreeNode* > &mp) {
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* parentNode = q.front();
        q.pop();
        if(parentNode->left) {
            mp[parentNode->left] = parentNode;
            q.push(parentNode->left);
        }
        if(parentNode->right) {
            mp[parentNode->right] = parentNode;
            q.push(parentNode->right);
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int distance) {
    unordered_map<TreeNode* , TreeNode* > parents;
    findParents(root, parents);
    // queue<TreeNode* , int> q;
    queue<TreeNode* > q;
    unordered_map<TreeNode* , bool> vis;
    q.push(target);
    vis[target] = true;
    int level = 0;
    while(!q.empty()) {
        if(level++ == distance) {
            // q contains the level k values
            break;
        }
        int n = q.size();
        for(int i = 0; i < n; i++) {
            TreeNode *parentNode = q.front();
            cout << parentNode->val<<" ";
            q.pop();
            if(parentNode->left && !vis[parentNode->left]) {
                vis[parentNode->left] = true;
                q.push(parentNode->left);
            }
            if(parentNode->right && !vis[parentNode->right]) {
                vis[parentNode->right] = true;
                q.push(parentNode->right);
            }
            //  Going up
            if(parents[parentNode] && !vis[parents[parentNode]]) {
                vis[parents[parentNode]] = true;
                q.push(parents[parentNode]);
            }
        }
        cout << endl;
    }
    vector<int> res;
    while(!q.empty()) {
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
}
};