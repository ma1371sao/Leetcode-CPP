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
	int min = 10000;
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		DFS(root, 1);
		return min;
	}
	void DFS(TreeNode* t, int num)
	{
		if (t->left)
			DFS(t->left, num + 1);
		if (t->right)
			DFS(t->right, num + 1);
		if (num<min && !t->left && !t->right)
			min = num;
	}
};