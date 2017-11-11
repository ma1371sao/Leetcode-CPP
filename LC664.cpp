class Solution {
public:
	int strangePrinter(string s) {
		int n = s.length();
		if (n == 0) return 0;
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				dp[j][i] = dp[j][i - 1] + 1;
				for (int k = j; k < i; k++) {
					if (s[k] == s[i])
						dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};