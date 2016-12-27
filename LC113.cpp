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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		if (root == NULL)  return ans;
		vector<int> v;
		v.push_back(root->val);
		dfs(root, sum, ans, v, root->val);
		return ans;
	}
	void dfs(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& v, int s) {
		if (root->left) {
			v.push_back(root->left->val);
			dfs(root->left, sum, ans, v, s + root->left->val);
			v.pop_back();
		}
		if (root->right) {
			v.push_back(root->right->val);
			dfs(root->right, sum, ans, v, s + root->right->val);
			v.pop_back();
		}
		if (root->left == NULL && root->right == NULL) {
			if (s == sum)
				ans.push_back(v);
		}
	}
};