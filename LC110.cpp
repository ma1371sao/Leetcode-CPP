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
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (DFS(root) == -1)
			return false;
		else
			return true;
	}
	int DFS(TreeNode* t)
	{
		int ln = 0, rn = 0;
		if (t->left)
		{
			ln = DFS(t->left) + 1;
			if (ln == 0)
				return -1;
		}
		if (t->right)
		{
			rn = DFS(t->right) + 1;
			if (rn == 0)
				return -1;
		}
		if ((ln - rn)<-1 || (ln - rn)>1)
			return -1;
		int d;
		if (ln >= rn)
			d = ln;
		else
			d = rn;
		return d;
	}
};