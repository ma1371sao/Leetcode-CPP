class Solution {
public:
	int numDistinct(string s, string t) {
		int n1 = s.length();
		int n2 = t.length();
		if (n1 < n2) return 0;
		if (n2 == 0) return 0;
		vector<vector<int>> dp(n1, vector<int>(n2, 0));
		if (s[0] == t[0]) dp[0][0] = 1;
		for (int i = 1; i < n1; i++) {
			if (s[i] == t[0])
				dp[i][0] = 1 + dp[i - 1][0];
			else
				dp[i][0] = dp[i - 1][0];
		}
		for (int i = 1; i < n1; i++) {
			for (int j = 1; j <= i && j < n2; j++) {
				if (s[i] == t[j])
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[n1 - 1][n2 - 1];
	}
};