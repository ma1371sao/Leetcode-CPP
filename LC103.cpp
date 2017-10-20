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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<pair<TreeNode*, int>> nodes;
		nodes.push(make_pair(root, 0));
		vector<int> floorNodes;
		int cur = 0;
		while (!nodes.empty()) {
			TreeNode* p = nodes.front().first;
			int depth = nodes.front().second;
			nodes.pop();
			if (cur == depth)
				floorNodes.push_back(p->val);
			else {
				res.push_back(floorNodes);
				floorNodes.clear();
				cur++;
				floorNodes.push_back(p->val);
			}
			if (p->left) nodes.push(make_pair(p->left, depth + 1));
			if (p->right) nodes.push(make_pair(p->right, depth + 1));
		}
		res.push_back(floorNodes);
		for (int i = 0; i < res.size(); i++) {
			if (i % 2)
				reverse(res[i].begin(), res[i].end());
		}
		return res;
	}
};