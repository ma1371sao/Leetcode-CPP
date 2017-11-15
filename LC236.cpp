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
		if (root == p || root == q || root == NULL) return root;
		TreeNode* LCA = NULL;
		dfs(root, p, q, LCA);
		return LCA;
	}

	int dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* & LCA) {
		if (root == NULL) return 0;
		int find = 0;
		if (root == p || root == q) find++;
		find += dfs(root->left, p, q, LCA);
		find += dfs(root->right, p, q, LCA);
		if (find == 2 && LCA == NULL)
			LCA = root;
		return find;
	}
};