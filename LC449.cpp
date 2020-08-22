/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
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
        if (data == "") return NULL;
        long long up = INT_MAX;
        up++;
        long long down = INT_MIN;
        down--;
        
        int idx = data.find(" ");
        int d = stoul(data.substr(0, idx), nullptr, 10);
        TreeNode* root = new TreeNode(d);
        dPreorder(root, data, up, down, idx + 1);
        return root;
    }
    
    void preorder(TreeNode* root, string& s) {
        if (!root) return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    int dPreorder(TreeNode* root, string& data, long long up, long long down, int i) {
        if (i == data.length()) return i;
        int idx = data.find(" ", i);
        int d = stoul(data.substr(i, idx), nullptr, 10);
        if (d <= down || d >= up) return i;
        
        if (d < root->val) {
            root->left = new TreeNode(d);
            i = dPreorder(root->left, data, root->val, down, idx + 1);
            if (i == data.length()) return data.length();
            
            idx = data.find(" ", i);
            d = stoul(data.substr(i, idx), nullptr, 10);
            if (d <= down || d >= up) return i;
            if (d > root->val) {
                root->right = new TreeNode(d);
                return dPreorder(root->right, data, up, root->val, idx + 1);
            }
        }
        
        if (d > root->val) {
            root->right = new TreeNode(d);
            return dPreorder(root->right, data, up, root->val, idx + 1);
        }
        return data.length();
    }
};

class Codec2 {
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
