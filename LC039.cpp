class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> combinations;
		vector<int> nums;
		dfs(candidates, target, combinations, nums, 0);
		return combinations;
	}

	void dfs(vector<int>& candidates, int target, vector<vector<int>>& combinations, vector<int>& nums, int pos) {
		if (target == 0) {
			combinations.push_back(nums);
			return;
		}
		if (target < 0 || pos >= candidates.size()) return;
		vector<int> v = nums;
		for (int i = 1; target - i * candidates[pos] >= 0; i++) {
			v.push_back(candidates[pos]);
			dfs(candidates, target - i * candidates[pos], combinations, v, pos + 1);
		}
		dfs(candidates, target, combinations, nums, pos + 1);
	}
};