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
	int findBottomLeftValue(TreeNode* root) {
		if (root == NULL) return 0;
		int res = root->val;
		queue<pair<TreeNode*, int>> que;
		que.push(make_pair(root, 0));
		int curDepth = 0;
		while (!que.empty()) {
			TreeNode* node = que.front().first;
			int depth = que.front().second;
			que.pop();
			if (node->left) que.push(make_pair(node->left, depth + 1));
			if (node->right) que.push(make_pair(node->right, depth + 1));
			if (depth > curDepth) {
				curDepth = depth;
				res = node->val;
			}
		}
		return res;
	}
};