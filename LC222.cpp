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
	int countNodes(TreeNode* root) {
		if (!root)   return 0;
		int leftdepth = 0;
		int rightdepth = 0;
		for (TreeNode* p = root; p != NULL; p = p->left)
			leftdepth++;
		for (TreeNode* p = root; p != NULL; p = p->right)
			rightdepth++;
		if (leftdepth == rightdepth)
			return (1 << leftdepth) - 1;
		else
			return 1 + countNodes(root->left) + countNodes(root->right);
	}
};