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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)   return res;
		PT(res, root);
		return res;
	}
	void PT(vector<int>& res, TreeNode* root) {
		res.push_back(root->val);
		if (root->left)  PT(res, root->left);
		if (root->right) PT(res, root->right);
	}
};

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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)   return res;
		stack<TreeNode*> s;
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				res.push_back(root->val);
				root = root->left;
			}
			root = s.top();
			s.pop();
			root = root->right;
		}
		return res;
	}
};