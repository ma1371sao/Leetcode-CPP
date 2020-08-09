/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution1 {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node* p = root;
        Node* nxtLvFirstNd = NULL;
        Node* pre = NULL;
        while (p) {
            if (p->left) {
                if (!nxtLvFirstNd) nxtLvFirstNd = p->left;
                p->left->next = p->right;
                if (pre) pre->next = p->left;
                pre = p->right;
            }
            
            if (p->next) p = p->next;
            else {
                p = nxtLvFirstNd;
                nxtLvFirstNd = NULL;
                pre = NULL;
            }
        }
        return root;
    }
};

class Solution2 {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		queue<pair<TreeLinkNode*, int>> nodes;
		nodes.push(make_pair(root, 0));
		while (!nodes.empty()) {
			TreeLinkNode* p = nodes.front().first;
			int depth = nodes.front().second;
			nodes.pop();
			if (p->left) nodes.push(make_pair(p->left, depth + 1));
			if (p->right) nodes.push(make_pair(p->right, depth + 1));
			if (!nodes.empty() && nodes.front().second == depth)
				p->next = nodes.front().first;
		}
	}
};
