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
	TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> q;
		if (!root)
			return root;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* p = q.front()->left;
			q.front()->left = q.front()->right;
			q.front()->right = p;
			if (q.front()->left != NULL)
				q.push(q.front()->left);
			if (q.front()->right != NULL)
				q.push(q.front()->right);
			q.pop();
		}
		return root;
	}
};