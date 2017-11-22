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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) return t2;
		if (t2 == NULL) return t1;
		TreeNode* root = new TreeNode(0);
		dfs(root, t1, t2);
		return root;
	}

	void dfs(TreeNode* root, TreeNode* t1, TreeNode* t2) {
		if (t1 && t2) {
			root->val = t1->val + t2->val;
			if (t1->left || t2->left) {
				root->left = new TreeNode(0);
				dfs(root->left, t1->left, t2->left);
			}
			if (t1->right || t2->right) {
				root->right = new TreeNode(0);
				dfs(root->right, t1->right, t2->right);
			}
		}
		else if (t1) {
			root->val = t1->val;
			if (t1->left) {
				root->left = new TreeNode(0);
				dfs(root->left, t1->left, NULL);
			}
			if (t1->right) {
				root->right = new TreeNode(0);
				dfs(root->right, t1->right, NULL);
			}
		}
		else if (t2) {
			root->val = t2->val;
			if (t2->left) {
				root->left = new TreeNode(0);
				dfs(root->left, NULL, t2->left);
			}
			if (t2->right) {
				root->right = new TreeNode(0);
				dfs(root->right, NULL, t2->right);
			}
		}
	}
};