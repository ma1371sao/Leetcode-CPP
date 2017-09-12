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
	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> mostFrequent;
		if (root == NULL) return mostFrequent;
		unordered_map<int, int> frequency;
		int max = 0;
		dfs(frequency, root, max);
		for (auto it = frequency.begin(); it != frequency.end(); it++)
			if (it->second == max)
				mostFrequent.push_back(it->first);
		return mostFrequent;
	}

	int dfs(unordered_map<int, int>& frequency, TreeNode* root, int& max) {
		if (root == NULL) return 0;
		int left = dfs(frequency, root->left, max);
		int right = dfs(frequency, root->right, max);
		int sum = left + right + root->val;
		frequency[sum]++;
		if (frequency[sum] > max) max = frequency[sum];
		return sum;
	}
};