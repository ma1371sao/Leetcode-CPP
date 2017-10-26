class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, -1);
		dp[1] = 1;
		return dfs(1, n, dp);
	}
	int dfs(int start, int end, vector<int>& dp) {
		if (start >= end) return 1;
		if (dp[end - start + 1] >= 0) return dp[end - start + 1];
		int num = 0;
		for (int i = start; i <= end; i++) {
			num += dfs(start, i - 1, dp) * dfs(i + 1, end, dp);
		}
		dp[end - start + 1] = num;
		return num;
	}
};