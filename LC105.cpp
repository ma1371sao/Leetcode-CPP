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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		if (inorder.size() != n || n == 0)   return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		unordered_map<int, int> hashin;
		for (int i = 0; i<n; i++)
			hashin[inorder[i]] = i;
		vector<bool> vis(n, false);
		vis[hashin[preorder[0]]] = true;
		int pos = 0;
		if (hashin[preorder[0]]>0)
			pos = dfs(preorder, inorder, hashin, pos + 1, root, 0, vis);
		if (hashin[preorder[0]]<n - 1)
			dfs(preorder, inorder, hashin, pos + 1, root, 1, vis);
		return root;
	}
	int dfs(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& hashin, int pos, TreeNode* root, int flag, vector<bool>& vis) {
		int cur = pos;
		if (flag) {
			root->right = new TreeNode(preorder[cur]);
			vis[hashin[preorder[cur]]] = true;
			if (hashin[preorder[cur]] - 1 >= 0 && !vis[hashin[preorder[cur]] - 1])
				pos = dfs(preorder, inorder, hashin, pos + 1, root->right, 0, vis);
			if (hashin[preorder[cur]] + 1<preorder.size() && !vis[hashin[preorder[cur]] + 1])
				pos = dfs(preorder, inorder, hashin, pos + 1, root->right, 1, vis);
			return pos;
		}
		else {
			root->left = new TreeNode(preorder[cur]);
			vis[hashin[preorder[cur]]] = true;
			if (hashin[preorder[cur]] - 1 >= 0 && !vis[hashin[preorder[cur]] - 1])
				pos = dfs(preorder, inorder, hashin, pos + 1, root->left, 0, vis);
			if (hashin[preorder[cur]] + 1<preorder.size() && !vis[hashin[preorder[cur]] + 1])
				pos = dfs(preorder, inorder, hashin, pos + 1, root->left, 1, vis);
			return pos;
		}
	}
};