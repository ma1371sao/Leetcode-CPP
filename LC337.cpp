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
    int rob(TreeNode* root) {
        vector<int> robMoney = dfs(root);
        return robMoney[1];
    }
    
    vector<int> dfs(TreeNode* root) {
        vector<int> robMoney(2, 0);
        if (root == NULL) return robMoney;
        vector<int> left_robMoney = dfs(root->left);
        vector<int> right_robMoney = dfs(root->right);
        robMoney[0] = left_robMoney[1] + right_robMoney[1];
        robMoney[1] = max(left_robMoney[0] + right_robMoney[0] + root->val, robMoney[0]);
        return robMoney;
    }
};