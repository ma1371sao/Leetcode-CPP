class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> dp(s.length() + 1, 0);
		int maxLen = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == '(')
				dp[i + 1] = 0;
			else {
				if (s[i - 1] == '(') {
					dp[i + 1] = dp[i - 1] + 2;
					maxLen = max(maxLen, dp[i + 1]);
				}
				else if (s[i - 1 - dp[i]] == '(') {
					dp[i + 1] = 2 + dp[i] + dp[i - 1 - dp[i]];
					maxLen = max(maxLen, dp[i + 1]);
				}
			}
		}
		return maxLen;
	}
};