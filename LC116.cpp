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
		TreeLinkNode *p;
		if (root == NULL)
			return;
		queue<TreeLinkNode*> q;
		q.push(root);
		q.push(NULL);
		int numf = 1;
		int nxtf = 0;
		int num = 0;
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
				q.push(p->left);
				nxtf++;
			}
			if (p->right)
			{
				q.push(p->right);
				nxtf++;
			}
			if (num == numf)
			{
				if (nxtf)
					q.push(NULL);
				num = 0;
				numf = nxtf;
				nxtf = 0;
			}
		}
	}
};