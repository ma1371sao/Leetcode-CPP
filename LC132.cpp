class Solution {
public:
	int minCut(string s) {
		vector<int> dp(s.length() + 1, 0);
		vector<vector<bool>> pal(s.length(), vector<bool>(s.length(), false));
		for (int i = 1; i < s.length(); i++) {
			dp[i + 1] = dp[i] + 1;
			for (int j = 0; j < i; j++) {
				if (s[j] == s[i] && (i - j <= 2 || pal[j + 1][i - 1])) {
					pal[j][i] = true;
					if (j == 0)
						dp[i + 1] = 0;
					else
						dp[i + 1] = min(dp[i + 1], dp[j] + 1);
				}
			}
		}
		return dp[s.length()];
	}
};