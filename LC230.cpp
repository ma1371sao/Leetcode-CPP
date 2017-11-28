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
	int kthSmallest(TreeNode* root, int k) {
		int numLeft = countNodes(root->left);
		if (k <= numLeft) return kthSmallest(root->left, k);
		if (k > numLeft + 1) return kthSmallest(root->right, k - numLeft - 1);
		return root->val;
	}

	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		return countNodes(root->left) + 1 + countNodes(root->right);
	}
};