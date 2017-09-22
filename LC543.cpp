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
	int diameterOfBinaryTree(TreeNode* root) {
		int maxPath = 0;
		if (root == NULL) return 0;
		maxDepth(root, maxPath);
		return maxPath - 1;
	}
	int maxDepth(TreeNode* root, int& maxPath) {
		if (root == NULL) return 0;
		int maxLeft = maxDepth(root->left, maxPath);
		int maxRight = maxDepth(root->right, maxPath);
		if (maxPath < maxLeft + maxRight + 1) maxPath = maxLeft + maxRight + 1;
		return max(maxLeft, maxRight) + 1;
	}
};