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
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		while (root->left || root->right) {
			TreeNode* cur = root;
			if (cur->left) {
				TreeNode* right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
				while (cur->right) cur = cur->right;
				cur->right = right;
			}
			root = root->right;
		}
	}
};