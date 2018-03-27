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
        vector<int> maxRob = dfs(root);
        return max(maxRob[0], maxRob[1]);
    }
    
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            vector<int> maxRob(2, 0);
            return maxRob;
        }
        vector<int> maxRob_l = dfs(root->left);
        vector<int> maxRob_r = dfs(root->right);
        vector<int> maxRob(2); //0: not include root; 1: include
        maxRob[0] = maxRob_l[1] + maxRob_r[1];
        maxRob[1] = max(root->val + maxRob_l[0] + maxRob_r[0], maxRob[0]);
        return maxRob;
    }
};