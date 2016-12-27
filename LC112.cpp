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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		if (DFS(root, sum, 0))
			return true;
		else
			return false;
	}
	bool DFS(TreeNode* t, int sum, int count)
	{
		count += t->val;
		if (!t->left && !t->right && count == sum)
			return true;
		if (t->left)
			if (DFS(t->left, sum, count))
				return true;
		if (t->right)
			if (DFS(t->right, sum, count))
				return true;
		return false;
	}
};