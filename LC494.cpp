class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		if (nums.size() == 0) return 0;
		int num = 0;
		dfs(nums, S, num, 0, 0);
		return num;
	}

	void dfs(vector<int>& nums, int S, int& num, int index, int sum) {
		if (index == nums.size()) {
			if (sum == S) {
				num++;
			}
			return;
		}
		dfs(nums, S, num, index + 1, sum + nums[index]);
		dfs(nums, S, num, index + 1, sum - nums[index]);
	}
};