class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == NULL) return NULL;
        Node* succ = NULL;
        Node* root = node->right;
        if (root) {
            while (root) {
                succ = root;
                root = root->left;
            }
            return succ;
        }
        
        while (node->parent) {
            if (node == node->parent->left) return node->parent;
            node = node->parent;
        }
        return succ;
    }
};
