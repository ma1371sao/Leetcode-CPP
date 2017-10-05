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
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		else if (!s) return false;
		else if (!t) return true;
		return dfs(s, t, 0);
	}
	bool dfs(TreeNode* s, TreeNode* t, int beginJudge) {
		if (!s && !t) return true;
		else if (!s || !t) return false;
		if (s->val == t->val && dfs(s->left, t->left, 1) && dfs(s->right, t->right, 1))
			return true;
		if (beginJudge) return false;
		if (s->left) {
			if (dfs(s->left, t, 0))
				return true;
		}
		if (s->right) {
			if (dfs(s->right, t, 0))
				return true;
		}
		return false;
	}
};