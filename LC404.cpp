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
	int ans;
	int sumOfLeftLeaves(TreeNode* root) {
		ans = 0;
		if (root == NULL)
			return ans;
		DFS(root);
		return ans;
	}
	void DFS(TreeNode* p)
	{
		if (p->left)
		{
			if (p->left->left == NULL && p->left->right == NULL)
				ans = ans + p->left->val;
			DFS(p->left);
		}
		if (p->right)
			DFS(p->right);
	}
};