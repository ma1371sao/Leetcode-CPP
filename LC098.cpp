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
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		long upbound = INT_MAX;
		long lowbound = INT_MIN;
		return isValid(root, upbound + 1, lowbound - 1);
	}
	bool isValid(TreeNode* root, long upbound, long lowbound) {
		if (root->val >= upbound || root->val <= lowbound) return false;
		if (root->left) {
			if (!isValid(root->left, root->val, lowbound)) return false;
		}
		if (root->right) {
			if (!isValid(root->right, upbound, root->val)) return false;
		}
		return true;
	}
};