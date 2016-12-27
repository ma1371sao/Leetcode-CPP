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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *ans;
		if (p == q)
			return p;
		if (p->val<q->val)
			ans = BST(root, p, q);
		else
			ans = BST(root, q, p);
		return ans;
	}
	TreeNode* BST(TreeNode* fa, TreeNode* l, TreeNode* r)
	{
		if (fa == l || fa == r)
			return fa;
		if (fa->val > l->val && fa->val < r->val)
			return fa;
		if (fa->val > r->val)
			return BST(fa->left, l, r);
		if (fa->val < l->val)
			return BST(fa->right, l, r);
		return fa;
	}
};