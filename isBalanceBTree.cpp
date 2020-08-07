struct TreeNode {
    int val;
    TreeNode *left, *right;
};

bool isBalanceTree(TreeNode* root) {
    int d = dfs(root);
    if (d == -1) return false;
    return true;
}

int dfs(TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = dfs(root->left);
    int rightDepth = dfs(root->right);
    if (leftDepth == -1 || rightDepth == -1) return -1;
    if (abs(rightDepth - leftDepth) > 1) return -1;
    return 1 + max(leftDepth, rightDepth);
}

