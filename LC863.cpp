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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        if (root == NULL || target == NULL) return ans;
        dfs(root, target, 0, K, ans, false);
        return ans;
    }
    
    int dfs(TreeNode* root, TreeNode* target, int dis, int K, vector<int>& ans, bool found) {
        if (root == target) found = true;
        if (found) {
            if (dis == K) {
                ans.push_back(root->val);
                return 0;
            }
            
            if (root->left) dfs(root->left, target, dis + 1, K, ans, true);
            if (root->right) dfs(root->right, target, dis + 1, K, ans, true);
            if (root == target) return 1;
            return 0;
        }
        
        if (root->left) {
            int newDis = dfs(root->left, target, 0, K, ans, false);
            if (newDis == K && K > 0) {
                ans.push_back(root->val);
                return 0;
            } else if (newDis > 0 && newDis < K) {
                if (root->right)
                    dfs(root->right, target, newDis + 1, K, ans, true);
                return newDis + 1;
            }
        }
        if (root->right) {
            int newDis = dfs(root->right, target, 0, K, ans, false);
            if (newDis == K && K > 0) {
                ans.push_back(root->val);
                return 0;
            } else if (newDis > 0 && newDis < K) {
                if (root->left)
                    dfs(root->left, target, newDis + 1, K, ans, true);
                return newDis + 1;
            }
        }
        return 0;
    }
};
