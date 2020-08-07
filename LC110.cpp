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
    bool isBalanced(TreeNode* root) {
        int d = dfs(root);
        if (d == -1) return false;
        return true;
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int leftD = dfs(root->left);
        int rightD = dfs(root->right);
        if (leftD == -1 || rightD == -1) return -1;
        if (abs(rightD - leftD) > 1) return -1;
        return 1 + max(leftD, rightD);
    }
};
