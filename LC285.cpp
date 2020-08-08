//O(logn)
class Solution1 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p == NULL) return NULL;
        TreeNode* succ = NULL;
        while(root) {
            if (p->val < root->val) {
                succ = root;
                root = root->left;
            } else
                root = root->right;
        }
        return succ;
    }
};

//O(n)
class Solution2 {
public:
    TreeNode* pre = NULL, *succ = NULL;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p == NULL) return NULL;
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
