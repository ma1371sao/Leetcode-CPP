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
    TreeNode* lca;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        lca = NULL;
        dfs(root, p, q);
        return lca;
    }
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int count = 0;
        if (root->val == p->val || root->val == q->val) count = 1;
        int left = dfs(root->left, p, q);
        if (lca) return 2;
        int right = dfs(root->right, p, q);
        if (lca) return 2;
        if (count + left + right == 2)
            lca = root;
        return left + right + count;
    }
};
