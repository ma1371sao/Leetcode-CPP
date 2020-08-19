class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        if (root->left || root->right) ans.push_back(root->val);
        getLeft(root->left, ans);
        getLeaves(root, ans);
        getRight(root->right, ans);
        return ans;
    }
    
    void getLeft(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (root->left) {
            ans.push_back(root->val);
            getLeft(root->left, ans);
        } else if (root->right) {
            ans.push_back(root->val);
            getLeft(root->right, ans);
        }
    }
    
    void getLeaves(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) ans.push_back(root->val);
        getLeaves(root->left, ans);
        getLeaves(root->right, ans);
    }
    
    void getRight(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (root->right) {
            ans.push_back(root->val);
            getRight(root->right, ans);
        } else if (root->left) {
            ans.push_back(root->val);
            getRight(root->left, ans);
        }
    }
};
