/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//DFS
class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "" || data == "# ") return NULL;
        int idx = data.find(" ");
        int d = stoul(data.substr(0, idx), nullptr, 10);
        TreeNode* root = new TreeNode(d);
        dPreorder(root, data, idx + 1);
        return root;
    }
    
    void preorder(TreeNode* root, string& s) {
        if (!root) {
            s += "# ";
            return;
        }
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    int dPreorder(TreeNode* root, string& data, int i) {
        if (i == data.length()) return i;
        int idx = data.find(" ", i);
        if (data.substr(i, idx - i) != "#") {
            int d = stoul(data.substr(i, idx - i), nullptr, 10);
            root->left = new TreeNode(d);
            i = dPreorder(root->left, data, idx + 1);
            
            idx = data.find(" ", i);
            if (data.substr(i, idx - i) != "#") {
                int d = stoul(data.substr(i, idx - i), nullptr, 10);
                root->right = new TreeNode(d);
                return dPreorder(root->right, data, idx + 1);
            } else
                return idx + 1;
        } else {
            i = idx + 1;
            idx = data.find(" ", i);
            if (data.substr(i, idx - i) != "#") {
                int d = stoul(data.substr(i, idx - i), nullptr, 10);
                root->right = new TreeNode(d);
                return dPreorder(root->right, data, idx + 1);
            } else
                return idx + 1;
        }
        return i;
    }
};

//BFS
class Codec2 {
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
