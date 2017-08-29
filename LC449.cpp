/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream encoded;
		dfs(root, encoded);
		return encoded.str();
	}

	void dfs(TreeNode* root, ostringstream& encoded) {
		if (root) {
			encoded << root->val << " ";
			dfs(root->left, encoded);
			dfs(root->right, encoded);
		}
		else {
			encoded << "# ";
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream bst(data);
		return reconstruct(bst);
	}

	TreeNode* reconstruct(istringstream& data) {
		string val = "";
		data >> val;
		if (val == "#") {
			return NULL;
		}
		stringstream ss(val);
		int n;
		ss >> n;
		TreeNode* root = new TreeNode(n);
		root->left = reconstruct(data);
		root->right = reconstruct(data);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));