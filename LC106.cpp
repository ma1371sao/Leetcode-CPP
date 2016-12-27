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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		if (postorder.size() != n || n == 0) return NULL;
		TreeNode* root = new TreeNode(postorder[n - 1]);
		unordered_map<int, int> hashin;
		for (int i = 0; i<n; i++)
			hashin[inorder[i]] = i;
		int pos = n - 1;
		vector<bool> vis(n, false);
		vis[hashin[postorder[n - 1]]] = true;
		if (hashin[postorder[n - 1]]<n - 1)
			pos = dfs(inorder, postorder, hashin, root, pos - 1, 1, vis);
		if (hashin[postorder[n - 1]]>0)
			pos = dfs(inorder, postorder, hashin, root, pos - 1, 0, vis);
		return root;
	}
	int dfs(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& hashin, TreeNode* root, int pos, int flag, vector<bool> vis) {
		int cur = pos;
		if (flag) {
			root->right = new TreeNode(postorder[cur]);
			vis[hashin[postorder[cur]]] = true;
			if (hashin[postorder[cur]] + 1<inorder.size() && !vis[hashin[postorder[cur]] + 1])
				pos = dfs(inorder, postorder, hashin, root->right, pos - 1, 1, vis);
			if (hashin[postorder[cur]] - 1 >= 0 && !vis[hashin[postorder[cur]] - 1])
				pos = dfs(inorder, postorder, hashin, root->right, pos - 1, 0, vis);
		}
		else {
			root->left = new TreeNode(postorder[cur]);
			vis[hashin[postorder[cur]]] = true;
			if (hashin[postorder[cur]] + 1<inorder.size() && !vis[hashin[postorder[cur]] + 1])
				pos = dfs(inorder, postorder, hashin, root->left, pos - 1, 1, vis);
			if (hashin[postorder[cur]] - 1 >= 0 && !vis[hashin[postorder[cur]] - 1])
				pos = dfs(inorder, postorder, hashin, root->left, pos - 1, 0, vis);
		}
		return pos;
	}
};