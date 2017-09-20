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
	int getMinimumDifference(TreeNode* root) {
		if (root == NULL) return 0;
		vector<int> nums;
		dfs(root, nums);
		sort(nums.begin(), nums.end());
		int minDiff = INT_MAX;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i + 1] - nums[i] < minDiff) minDiff = nums[i + 1] - nums[i];
		}
		return minDiff;
	}
	void dfs(TreeNode* root, vector<int>& nums) {
		nums.push_back(root->val);
		if (root->left) {
			dfs(root->left, nums);
		}
		if (root->right) {
			dfs(root->right, nums);
		}
	}
};