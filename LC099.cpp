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
	vector<TreeNode*> node;
	void recoverTree(TreeNode* root) {
		if (root == NULL)  return;
		DFS(root);
		int p[2];
		int num = 0;
		for (int i = 0; i<node.size() - 1; i++) {
			if (node[i]->val>node[i + 1]->val) {
				p[num] = i;
				num++;
			}
		}
		if (num == 1) {
			int tmp = node[p[0]]->val;
			node[p[0]]->val = node[p[0] + 1]->val;
			node[p[0] + 1]->val = tmp;
		}
		if (num == 2) {
			int tmp = node[p[0]]->val;
			node[p[0]]->val = node[p[1] + 1]->val;
			node[p[1] + 1]->val = tmp;
		}
	}
	void DFS(TreeNode* p) {
		if (p->left)
			DFS(p->left);
		node.push_back(p);
		if (p->right)
			DFS(p->right);
	}
};