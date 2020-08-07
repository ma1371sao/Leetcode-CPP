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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return dfs(root, sum, 0, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int dfs(TreeNode* root, int sum, int val, int num) {
        val += root->val;
        if (val == sum) num++;
        
        if (root->left)
            num = dfs(root->left, sum, val, num);
        if (root->right)
            num = dfs(root->right, sum, val, num);
        return num;
    }
};
