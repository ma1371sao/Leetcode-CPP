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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        insertNode(root, val);
        return root;
    }
    
    void insertNode(TreeNode* root, int val) {
        if (val > root->val) {
            if (root->right != NULL) {
                insertNode(root->right, val);
            } else {
                root->right = new TreeNode(val);
                return;
            }
        }
        if (val < root->val) {
            if (root->left != NULL) {
                insertNode(root->left, val);
            } else {
                root->left = new TreeNode(val);
                return;
            }
        }
    }
};
