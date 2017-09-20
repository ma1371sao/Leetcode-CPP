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
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL) return NULL;
		vector<int> nums;
		int sum = 0;
		dfs(root, nums, sum);
		sort(nums.begin(), nums.end());
		unordered_map<int, int> addedNum;
		for (int i = 0; i < nums.size(); i++) {
			addedNum[nums[i]] = sum - nums[i];
			sum -= nums[i];
		}
		addNum(root, addedNum);
		return root;
	}
	void dfs(TreeNode* root, vector<int>& nums, int& sum) {
		nums.push_back(root->val);
		sum += root->val;
		if (root->left) dfs(root->left, nums, sum);
		if (root->right) dfs(root->right, nums, sum);
	}
	void addNum(TreeNode* root, unordered_map<int, int>& addedNum) {
		root->val += addedNum[root->val];
		if (root->left) addNum(root->left, addedNum);
		if (root->right) addNum(root->right, addedNum);
	}
};