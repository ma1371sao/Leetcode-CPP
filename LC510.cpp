class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == NULL) return NULL;
        Node* succ = NULL;
        if (node->right) {
            succ = node->right;
            while (succ->left) succ = succ->left;
            return succ;
    	}

        while (node->parent) {
            if (node == node->parent->left) return node->parent;
            node = node->parent;
        }
        return succ;
    }
};
