class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        TreeNode* pre = NULL, *succ = NULL;
        inorder(root, p);
        return succ;
    }
    
    void inorder(TreeNode* root, TreeNode* p) {
        if (root == NULL) return;
        inorder(root->left, p);
        if (pre == p) succ = root;
        pre = root;
        inorder(root->right, p);
    }
};
