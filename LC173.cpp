/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator {
public:
	stack<TreeNode*> st;
	BSTIterator(TreeNode *root) {
		findLeft(root);
	}

	void findLeft(TreeNode* root) {
		while (root) {
			st.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* smallest = st.top();
		st.pop();
		findLeft(smallest->right);
		return smallest->val;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/