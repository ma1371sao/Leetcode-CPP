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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)  return ans;
		queue<TreeNode*> q;
		q.push(root);
		int n = 0;
		int nf = 1;
		vector<int>* v = new vector<int>;
		int nxt = 0;
		bool flag = true;
		while (!q.empty()) {
			TreeNode* p = q.front();
			q.pop();
			n++;
			v->push_back(p->val);
			if (p->left) {
				q.push(p->left);
				nxt++;
			}
			if (p->right) {
				q.push(p->right);
				nxt++;
			}
			if (n == nf) {
				if (!flag) {
					vector<int>* tmp = new vector<int>;
					for (int i = v->size() - 1; i >= 0; i--)
						tmp->push_back((*v)[i]);
					ans.push_back(*tmp);
				}
				else
					ans.push_back(*v);
				v = new vector<int>;
				n = 0;
				nf = nxt;
				nxt = 0;
				flag = !flag;
			}
		}
		return ans;
	}
};