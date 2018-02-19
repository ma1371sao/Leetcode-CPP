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
    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode*, TreeNode*>> abnNodes;
        TreeNode *lastNode = NULL;
        dfs(root, abnNodes, &lastNode);
        if (abnNodes.size() == 1) {
            int tmp = abnNodes[0].first->val;
            abnNodes[0].first->val = abnNodes[0].second->val;
            abnNodes[0].second->val = tmp;
        }
        else if (abnNodes.size() == 2) {
            int tmp = abnNodes[0].first->val;
            abnNodes[0].first->val = abnNodes[1].second->val;
            abnNodes[1].second->val = tmp;
        }
    }
    
    void dfs(TreeNode *root, vector<pair<TreeNode*, TreeNode*>>& abnNodes, TreeNode **lastNode) {
        if (root->left)
            dfs(root->left, abnNodes, lastNode);
        if (*lastNode != NULL && root->val < (*lastNode)->val)
            abnNodes.push_back(make_pair(*lastNode, root));
        *lastNode = root;
        if (root->right)
            dfs(root->right, abnNodes, lastNode);
    }
};
