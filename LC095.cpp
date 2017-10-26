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
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> roots;
		if (n < 1) return roots;
		roots = construct(1, n);
		return roots;
	}
	vector<TreeNode*> construct(int start, int end) {
		vector<TreeNode*> roots;
		if (start > end) {
			TreeNode* p = NULL;
			roots.push_back(NULL);
			return roots;
		}
		if (start == end) {
			TreeNode* p = new TreeNode(start);
			roots.push_back(p);
			return roots;
		}
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> left = construct(start, i - 1);
			vector<TreeNode*> right = construct(i + 1, end);
			for (int j = 0; j < left.size(); j++) {
				for (int k = 0; k < right.size(); k++) {
					TreeNode* p = new TreeNode(i);
					p->left = left[j];
					p->right = right[k];
					roots.push_back(p);
				}
			}
		}
		return roots;
	}
};