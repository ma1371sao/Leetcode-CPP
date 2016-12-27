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
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		TreeNode* t = root;
		while (t->left != NULL || t->right != NULL) {
			TreeNode* tt = t;
			if (t->left)
			{
				TreeNode* p = t->right;
				t->right = t->left;
				t->left = NULL;
				while (t->right) t = t->right;
				t->right = p;
			}
			t = tt->right;
		}
	}
};