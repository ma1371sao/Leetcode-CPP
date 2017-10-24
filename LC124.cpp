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
	int maxPathSum(TreeNode* root) {
		int maxSum = INT_MIN;
		findMaxSum(root, maxSum);
		return maxSum;
	}
	int findMaxSum(TreeNode* root, int& maxSum) {
		if (root == NULL) return 0;
		int l = findMaxSum(root->left, maxSum);
		int r = findMaxSum(root->right, maxSum);
		if (l < 0) l = 0;
		if (r < 0) r = 0;
		if (l + r + root->val > maxSum) maxSum = l + r + root->val;
		return max(l, r) + root->val;
	}
};