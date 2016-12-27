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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> v;
		if (root == NULL)
			return ans;
		queue<TreeNode*> q;
		q.push(root);
		int count = 1;
		int Nfloor = 0;
		int next = 1;
		v.push_back(root->val);
		while (!q.empty())
		{
			if (count == 2 * Nfloor || Nfloor == 0)
			{
				ans.push_back(v);
				v.erase(v.begin(), v.end());
				Nfloor = next;
				count = 0;
				next = 0;
			}
			if (q.front()->left)
			{
				q.push(q.front()->left);
				count++;
				next++;
				v.push_back(q.front()->left->val);
			}
			else
				count++;
			if (q.front()->right)
			{
				q.push(q.front()->right);
				count++;
				next++;
				v.push_back(q.front()->right->val);
			}
			else
				count++;
			q.pop();
		}
		return ans;
	}
};