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
	int rob(TreeNode* root) {
		if (!root)   return 0;
		vector<int> res = dfs(root);
		return res[1];
	}
	vector<int> dfs(TreeNode* root) {
		if (!root) {
			vector<int> v;
			v.push_back(0);
			v.push_back(0);
			return v;
		}
		vector<int> vleft = dfs(root->left);
		vector<int> vright = dfs(root->right);
		vector<int> v(2);
		v[0] = vleft[1] + vright[1];
		if (v[0]>root->val + vleft[0] + vright[0])
			v[1] = v[0];
		else
			v[1] = root->val + vleft[0] + vright[0];
		return v;
	}
};