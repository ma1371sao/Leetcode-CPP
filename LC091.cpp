class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0 || s[0] == '0')   return 0;
		vector<int>dp(s.length(), 0);
		dp[0] = 1;
		if (s.length()>1) {
			if (s[1] != '0')   dp[1] = 1;
			int tmp = (s[0] - 48) * 10 + s[1] - 48;
			if (tmp >= 10 && tmp <= 26)
				dp[1]++;
		}
		for (int i = 2; i<s.length(); i++) {
			if (s[i] != '0')   dp[i] = dp[i - 1];
			int tmp = (s[i - 1] - 48) * 10 + s[i] - 48;
			if (tmp >= 10 && tmp <= 26)   dp[i] = dp[i] + dp[i - 2];
		}
		return dp[s.length() - 1];
	}
};