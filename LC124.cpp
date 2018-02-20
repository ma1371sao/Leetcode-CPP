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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMax(root, maxSum);
        return maxSum;
    }
    
    int findMax(TreeNode *root, int& maxSum) {
        if (root == NULL) return 0;
        int maxLeftSum = max(findMax(root->left, maxSum), 0);
        int maxRightSum = max(findMax(root->right, maxSum), 0);
        if (maxLeftSum + root->val + maxRightSum > maxSum)
            maxSum = maxLeftSum + root->val + maxRightSum;
        return max(maxLeftSum, maxRightSum) + root->val;
    }
};
