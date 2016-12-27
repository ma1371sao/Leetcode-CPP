class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.length();
		int n2 = s2.length();
		int n3 = s3.length();
		if (n1 + n2 != n3) return false;
		if (n1 == 0 && n2 == 0 && n3 == 0) return true;
		vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n1; i++)
			if (s1[i - 1] == s3[i - 1])
				dp[i][0] = dp[i - 1][0];
		for (int i = 1; i <= n2; i++)
			if (s2[i - 1] == s3[i - 1])
				dp[0][i] = dp[0][i - 1];
		for (int i = 1; i <= n1; i++)
			for (int j = 1; j <= n2; j++) {
				if (s1[i - 1] == s3[i + j - 1] || s2[j - 1] == s3[i + j - 1]) {
					if (s1[i - 1] == s2[j - 1]) {
						if (dp[i - 1][j] || dp[i][j - 1])
							dp[i][j] = true;
						else
							dp[i][j] = false;
					}
					else {
						if (s1[i - 1] == s3[i + j - 1])
							dp[i][j] = dp[i - 1][j];
						else
							dp[i][j] = dp[i][j - 1];
					}
				}
			}
		return dp[n1][n2];
	}
};