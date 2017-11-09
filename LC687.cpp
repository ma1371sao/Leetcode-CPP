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
	int longestUnivaluePath(TreeNode* root) {
		if (root == NULL) return 0;
		int maxLen = 0;
		dfs(root, maxLen, root->val);
		return maxLen - 1;
	}

	int dfs(TreeNode* root, int& maxLen, int lastVal) {
		if (root == NULL) return 0;
		int left = dfs(root->left, maxLen, root->val);
		int right = dfs(root->right, maxLen, root->val);
		int sum = left + right + 1;
		if (sum > maxLen) maxLen = sum;
		if (root->val == lastVal) return max(left, right) + 1;
		return 0;
	}
};