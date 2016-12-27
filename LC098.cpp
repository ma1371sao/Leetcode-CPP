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
		if (root == NULL)  return true;
		long long down = INT_MIN;
		long long up = INT_MAX;
		return DFS(root, down - 1, up + 1);
	}
	bool DFS(TreeNode* p, long long down, long long up) {
		if (p->left) {
			if (p->left->val<p->val && p->left->val>down) {
				if (!DFS(p->left, down, p->val))
					return false;
			}
			else
				return false;
		}
		if (p->right) {
			if (p->right->val>p->val && p->right->val<up) {
				if (!DFS(p->right, p->val, up))
					return false;
			}
			else
				return false;
		}
		return true;
	}
};