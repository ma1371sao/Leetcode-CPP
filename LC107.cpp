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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ans;
		if (root == NULL)
			return ans;
		q.push(root);
		while (!q.empty())
		{
			queue<TreeNode*>tem_q;
			vector<int> tem_v;
			while (!q.empty())
			{
				if (q.front()->left)
					tem_q.push(q.front()->left);
				if (q.front()->right)
					tem_q.push(q.front()->right);
				tem_v.push_back(q.front()->val);
				q.pop();
			}
			q = tem_q;
			ans.push_back(tem_v);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};