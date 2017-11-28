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
	int longestConsecutive(TreeNode* root) {
		int maxLen = 1;
		if (root == NULL) return 0;
		dfs(root, maxLen, 1);
		return maxLen;
	}

	void dfs(TreeNode* root, int& maxLen, int cur) {
		if (cur > maxLen) maxLen = cur;
		if (root->left) {
			if (root->left->val == root->val + 1) dfs(root->left, maxLen, cur + 1);
			else dfs(root->left, maxLen, 1);
		}
		if (root->right) {
			if (root->right->val == root->val + 1) dfs(root->right, maxLen, cur + 1);
			else dfs(root->right, maxLen, 1);
		}
	}
};