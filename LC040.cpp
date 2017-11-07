class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> combinations;
		vector<int> nums;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, combinations, nums, 0);
		return combinations;
	}

	void dfs(vector<int>& candidates, int target, vector<vector<int>>& combinations, vector<int>& nums, int pos) {
		if (target == 0) {
			combinations.push_back(nums);
			return;
		}
		if (target < 0 || pos >= candidates.size()) return;
		nums.push_back(candidates[pos]);
		dfs(candidates, target - candidates[pos], combinations, nums, pos + 1);
		nums.pop_back();
		for (; pos < candidates.size() - 1 && candidates[pos] == candidates[pos + 1]; pos++);
		dfs(candidates, target, combinations, nums, pos + 1);
	}
};