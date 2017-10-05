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
	int findTilt(TreeNode* root) {
		if (root == NULL) return 0;
		int sum = 0;
		dfs(root, sum);
		return sum;
	}
	int dfs(TreeNode* root, int& sum) {
		if (!root) return 0;
		int sumLeft = dfs(root->left, sum);
		int sumRight = dfs(root->right, sum);
		sum += abs(sumLeft - sumRight);
		return root->val + sumLeft + sumRight;
	}
};