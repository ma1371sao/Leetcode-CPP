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
	int ans = 0;
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return ans;
		TreeNode* p = root;
		Deph(p, 1);
		return ans;
	}
	void Deph(TreeNode* p, int d)
	{
		if (d>ans)
			ans = d;
		if (p->left)
			Deph(p->left, d + 1);
		if (p->right)
			Deph(p->right, d + 1);
	}
};