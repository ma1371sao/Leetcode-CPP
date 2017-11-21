class Solution {
public:
	string minWindow(string S, string T) {
		int sLen = S.length();
		int tLen = T.length();
		vector<vector<int>> dp(tLen, vector<int>(sLen, 0));
		bool found = false;
		int minLen = INT_MAX;
		int pos = -1;
		for (int c = 0; c < sLen; c++) {
			if (T[0] == S[c]) {
				dp[0][c] = 1;
				found = true;
			}
			else {
				dp[0][c] = found ? dp[0][c - 1] + 1 : 0;
			}
		}
		if (tLen == 1 && found) return T;
		for (int r = 1; r < tLen; r++) {
			for (int c = r; c < sLen; c++) {
				if (T[r] == S[c]) {
					if (dp[r - 1][c - 1] != 0) dp[r][c] = dp[r - 1][c - 1] + 1;
					else dp[r][c] = 0;
					if (r == tLen - 1 && dp[r][c] > 0) {
						if (dp[r][c] < minLen) {
							minLen = dp[r][c];
							pos = c;
						}
					}
				}
				else {
					if (dp[r][c - 1] != 0) dp[r][c] = dp[r][c - 1] + 1;
					else dp[r][c] = 0;
				}
			}
		}
		if (pos == -1) return "";
		return S.substr(pos - minLen + 1, minLen);
	}
};