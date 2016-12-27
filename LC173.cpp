/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct cmp {
	bool operator() (const int a, const int b) {
		return a>b;
	}
};
class BSTIterator {
public:
	TreeNode * r;
	priority_queue<int, vector<int>, cmp> pq;
	BSTIterator(TreeNode *root) {
		if (root == NULL)  return;
		dfs(root);
	}
	void dfs(TreeNode *root) {
		pq.push(root->val);
		if (root->left)  dfs(root->left);
		if (root->right) dfs(root->right);
	}
	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !pq.empty();
	}

	/** @return the next smallest number */
	int next() {
		int res = pq.top();
		pq.pop();
		return res;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/


//second solution

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
		TreeNode* nxtsml = st.top();
		st.pop();
		if (nxtsml->right) {
			TreeNode* root = nxtsml->right;
			while (root) {
				st.push(root);
				root = root->left;
			}
		}
		return nxtsml->val;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/