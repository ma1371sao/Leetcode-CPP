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
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL) return 0;
		return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
	int dfs(TreeNode* root, int sum) {
		int res = 0;
		if (root->val == sum) res++;
		int left = 0;
		int right = 0;
		if (root->left) left = dfs(root->left, sum - root->val);
		if (root->right) right = dfs(root->right, sum - root->val);
		return res + left + right;
	}
};