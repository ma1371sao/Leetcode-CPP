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
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		queue<TreeNode*> q;
		vector<TreeNode*> v;
		q.push(root);
		v.push_back(root);
		vector<TreeNode*>::iterator b = v.begin();
		vector<TreeNode*>::iterator e = v.end() - 1;
		int count = 1;
		bool flag = true;
		while (!q.empty())
		{
			b = v.begin();
			e = v.end() - 1;
			if (v.size() == count)
			{
				flag = Is_mirror(b, e);
				if (flag == false)
					return false;
				count = 0;
				for (; b != v.end(); b++)
					if ((*b) != NULL)
						count++;
				v.erase(v.begin(), v.end());
				count = count * 2;
			}
			if (q.front()->left)
			{
				q.push(q.front()->left);
				v.push_back(q.front()->left);
			}
			else
			{
				//TreeNode* tl=NULL;
				v.push_back(NULL);
			}
			if (q.front()->right)
			{
				q.push(q.front()->right);
				v.push_back(q.front()->right);
			}
			else
			{
				//TreeNode* tr=NULL;
				v.push_back(NULL);
			}
			q.pop();
		}
		return true;
	}
	bool Is_mirror(vector<TreeNode*>::iterator b, vector<TreeNode*>::iterator e)
	{
		for (int i = 0; (b + i)<(e - i); i++)
		{
			if (*(b + i) == NULL || *(e - i) == NULL)
			{
				if (*(b + i) != *(e - i))
					return false;
			}
			else if ((*(b + i))->val != (*(e - i))->val)
				return false;
		}
		return true;
	}
};