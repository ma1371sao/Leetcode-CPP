/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		TreeLinkNode *p;
		queue<TreeLinkNode*> q;
		q.push(root);
		q.push(NULL);
		int num = 0;
		int nfloor = 1;
		int nxtf = 0;
		while (!q.empty())
		{
			num++;
			p = q.front();
			q.pop();
			p->next = q.front();
			if (q.front() == NULL)
				q.pop();
			if (p->left)
			{
				nxtf++;
				q.push(p->left);
			}
			if (p->right)
			{
				nxtf++;
				q.push(p->right);
			}
			if (num == nfloor)
			{
				if (!q.empty())
					q.push(NULL);
				nfloor = nxtf;
				nxtf = 0;
				num = 0;
			}
		}
	}
};