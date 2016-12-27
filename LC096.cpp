class Solution {
public:
	int dp[1000][1000];
	int numTrees(int n) {
		if (n<1) return 0;
		for (int i = 1; i <= n; i++)
			memset(dp[i], 0, sizeof(dp[i]));
		return divide(1, n);
	}
	int divide(int start, int end) {
		int num = 0;
		for (int i = start; i <= end; i++) {
			if (dp[start][i - 1] == 0) {
				if (start>i - 1)   dp[start][i - 1] = 1;
				else    dp[start][i - 1] = divide(start, i - 1);
			}
			if (dp[i + 1][end] == 0) {
				if (i + 1>end)   dp[i + 1][end] = 1;
				else    dp[i + 1][end] = divide(i + 1, end);
			}
			num = num + dp[start][i - 1] * dp[i + 1][end];
		}
		return num;
	}
};