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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        unordered_map<int, int> val_inPos;
        for (int i = 0; i < n; i++)
            val_inPos[inorder[i]] = i;
        int pos = 0;
        if (val_inPos[preorder[0]] > 0)
            pos = construct(root, val_inPos, preorder, inorder, pos + 1, 0, val_inPos[preorder[pos]]);
        if (val_inPos[preorder[0]] < preorder.size() - 1)
            construct(root, val_inPos, preorder, inorder, pos + 1, 1, n);
        return root;
    }
    
    int construct(TreeNode* root, unordered_map<int, int>& val_inPos, vector<int>& preorder, vector<int>& inorder, int pos,
                  int flag, int rightLimit) {
        if (flag == 0) {
            root->left = new TreeNode(preorder[pos]);
            if (pos + 1 < preorder.size() && val_inPos[preorder[pos + 1]] < val_inPos[preorder[pos]])
                pos = construct(root->left, val_inPos, preorder, inorder, pos + 1, 0, val_inPos[preorder[pos]]);
            if (pos + 1 < preorder.size() && val_inPos[preorder[pos + 1]] < rightLimit)
                pos = construct(root->left, val_inPos, preorder, inorder, pos + 1, 1, rightLimit);
            return pos;
        }
        else {
            cout << pos << endl;
            root->right = new TreeNode(preorder[pos]);
            if (pos + 1 < preorder.size() && val_inPos[preorder[pos + 1]] < val_inPos[preorder[pos]])
                pos = construct(root->right, val_inPos, preorder, inorder, pos + 1, 0, val_inPos[preorder[pos]]);
            if (pos + 1 < preorder.size() && val_inPos[preorder[pos + 1]] < rightLimit)
                pos = construct(root->right, val_inPos, preorder, inorder, pos + 1, 1, rightLimit);
            return pos;
        }
    }
};
