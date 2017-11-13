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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		int sum = 0;
		dfs(root, sum, false);
		return sum;
	}

	void dfs(TreeNode* root, int& sum, bool isLeft) {
		if (root->left) dfs(root->left, sum, true);
		if (root->right) dfs(root->right, sum, false);
		if (root->left == NULL && root->right == NULL && isLeft)
			sum += root->val;
	}
};