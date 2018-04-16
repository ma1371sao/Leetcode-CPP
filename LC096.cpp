// 1. recursive solution
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

// 2. iterative solution
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};