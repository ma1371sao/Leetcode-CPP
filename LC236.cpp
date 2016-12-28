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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)   return NULL;
		if (p == root) return p;
		if (q == root) return q;
		if (p == q)    return p;
		if (dfs(p, q))  return p;
		if (dfs(q, p))  return q;
		vector<TreeNode*> routep;
		vector<TreeNode*> routeq;
		findroute(p, routep, root);
		findroute(q, routeq, root);
		unordered_map<TreeNode*, bool> hash;
		for (int i = 0; i<routep.size(); i++)
			hash[routep[i]] = true;
		for (int i = 0; i<routeq.size(); i++)
			if (hash.find(routeq[i]) != hash.end())
				return routeq[i];
		return NULL;
	}
	bool dfs(TreeNode* root, TreeNode* t) {
		if (root == t) return true;
		if (root->left)
			if (dfs(root->left, t))
				return true;
		if (root->right)
			if (dfs(root->right, t))
				return true;
		return false;
	}
	bool findroute(TreeNode* t, vector<TreeNode*>& route, TreeNode* root) {
		if (root == t) return true;
		if (root->left)
			if (findroute(t, route, root->left)) {
				route.push_back(root);
				return true;
			}
		if (root->right)
			if (findroute(t, route, root->right)) {
				route.push_back(root);
				return true;
			}
		return false;
	}
};