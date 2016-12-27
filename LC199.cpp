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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == NULL)  return res;
		TreeNode* p = root;
		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(p, 0));
		while (!q.empty()) {
			p = q.front().first;
			int depth = q.front().second;
			q.pop();
			if (p->left) q.push(make_pair(p->left, depth + 1));
			if (p->right)    q.push(make_pair(p->right, depth + 1));
			if (q.empty())   res.push_back(p->val);
			else if (q.front().second>depth) res.push_back(p->val);
		}
		return res;
	}
};