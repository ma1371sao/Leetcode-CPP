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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root == NULL) return res;
		dfs(root, res, "");
		return res;
	}

	void dfs(TreeNode* root, vector<string>& res, string curPath) {
		curPath += to_string(root->val);
		if (root->left) dfs(root->left, res, curPath + "->");
		if (root->right) dfs(root->right, res, curPath + "->");
		if (root->left == NULL && root->right == NULL) res.push_back(curPath);
	}
};