// 1. Recursive solution

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
	vector<int> ans;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL) return ans;
		DFS(root);
		return ans;
	}
	void DFS(TreeNode* p) {
		if (p->left) DFS(p->left);
		ans.push_back(p->val);
		if (p->right) DFS(p->right);
	}
};

// 2. Iterative solution

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> nodes;
        while (root) {
            nodes.push(root);
            root = root->left;
        }
        while (!nodes.empty()) {
            root = nodes.top();
            res.push_back(root->val);
            nodes.pop();
            if (root->right) {
                root = root->right;
                while (root) {
                    nodes.push(root);
                    root = root->left;
                }
            }
        }
        return res;
    }
};