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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        dfs(res, root);
        return res;
    }
    
    void dfs(vector<int>& res, TreeNode* root) {
        if (root->left) dfs(res, root->left);
        if (root->right) dfs(res, root->right);
        res.push_back(root->val);
    }
};
