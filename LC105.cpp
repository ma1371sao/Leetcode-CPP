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
    int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return NULL;
        unordered_map<int, int> val_idx;
        for (int i = 0; i < n; i++)
            val_idx[inorder[i]] = i;
        return dfs(preorder, val_idx, 0, n - 1);
    }
    
    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& val_idx, int l, int r) {
        if (l > r) return NULL;
        int val = preorder[idx];
        int pos = val_idx[val];
        if (pos < l || pos > r) return NULL;
        idx++;
        TreeNode* left = dfs(preorder, val_idx, l, pos - 1);
        TreeNode* right = dfs(preorder, val_idx, pos + 1, r);
        return new TreeNode(val, left, right);
    }
};
