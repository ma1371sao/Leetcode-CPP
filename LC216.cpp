class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k<1 || n<1)  return res;
		vector<int> nums;
		dfs(nums, k, n, 0, 1);
		return res;
	}
	void dfs(vector<int>& nums, int k, int n, int sum, int num) {
		if (!k) {
			if (sum == n)
				res.push_back(nums);
			return;
		}
		for (int i = num; i<10 && sum + i <= n; i++) {
			nums.push_back(i);
			dfs(nums, k - 1, n, sum + i, i + 1);
			nums.pop_back();
		}
	}
};