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
	vector<string> ans;
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL)
			return ans;
		DFS(root, "");
		return ans;
	}
	void DFS(TreeNode* p, string s)
	{
		string s_val = Inttostring(p->val);
		if (s == "")
			s = s + s_val;
		else
			s = s + "->" + s_val;
		if (p->left == NULL && p->right == NULL)
		{
			ans.push_back(s);
			return;
		}
		if (p->left)
			DFS(p->left, s);
		if (p->right)
			DFS(p->right, s);
	}
	string Inttostring(int val)
	{
		string s;
		vector<int> v;
		int flag = 0;
		if (val<0)
		{
			s.push_back('-');
			val = -val;
		}
		while (val)
		{
			int c = val % 10;
			v.push_back(c);
			val = val / 10;
		}
		for (int i = v.size() - 1; i >= 0; i--)
			s.push_back(v[i] + 48);
		return s;
	}
};