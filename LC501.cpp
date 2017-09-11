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
	vector<int> findMode(TreeNode* root) {
		vector<int> modes;
		if (root == NULL) return modes;
		unordered_map<int, int> count;
		int max = 0;
		dfs(root, count, max);
		for (auto it = count.begin(); it != count.end(); it++) {
			if (it->second == max)
				modes.push_back(it->first);
		}
		return modes;
	}

	void dfs(TreeNode* root, unordered_map<int, int>& count, int& max) {
		count[root->val]++;
		if (count[root->val] > max) max = count[root->val];
		if (root->left) dfs(root->left, count, max);
		if (root->right) dfs(root->right, count, max);
	}
};