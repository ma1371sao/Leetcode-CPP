class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
		dp[0][0] = true;
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == '*' && dp[0][j - 1])
				dp[0][j + 1] = true;
		}
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < p.length(); j++) {
				if (s[i] == p[j] || p[j] == '.')
					dp[i + 1][j + 1] = dp[i][j];
				else if (p[j] == '*') {
					if (s[i] != p[j - 1] && p[j - 1] != '.')
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					else {
						dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i][j] || dp[i + 1][j - 1]);
					}
				}
			}
		}
		return dp[s.length()][p.length()];
	}
};