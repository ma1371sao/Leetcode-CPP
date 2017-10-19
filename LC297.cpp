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
		queue<TreeNode*> nodes;
		string s;
		nodes.push(root);
		while (!nodes.empty()) {
			TreeNode* p = nodes.front();
			nodes.pop();
			if (p == NULL)
				s += "null,";
			else
				s += to_string(p->val) + ",";
			if (p) {
				nodes.push(p->left);
				nodes.push(p->right);
			}
		}
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int pos = data.find(',');
		if (data.substr(0, pos) == "null") return NULL;
		queue<TreeNode*> nodes;
		TreeNode* root = new TreeNode(stoi(data.substr(0, pos)));
		nodes.push(root);
		data = data.substr(pos + 1);
		while (!nodes.empty()) {
			TreeNode* p = nodes.front();
			nodes.pop();
			pos = data.find(',');
			string left = data.substr(0, pos);
			if (left != "null") {
				p->left = new TreeNode(stoi(left));
				nodes.push(p->left);
			}
			data = data.substr(pos + 1);
			pos = data.find(',');
			string right = data.substr(0, pos);
			if (right != "null") {
				p->right = new TreeNode(stoi(right));
				nodes.push(p->right);
			}
			data = data.substr(pos + 1);
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));