class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int r = matrix.size();
		if (r == 0) return 0;
		int c = matrix[0].size();
		vector<vector<int>> dp(r, vector<int>(c, 0));
		int maxLen = 0;
		for (int i = 0; i < r; i++)
			if (matrix[i][0] == '1') {
				dp[i][0] = 1;
				maxLen = 1;
			}
		for (int j = 0; j < c; j++)
			if (matrix[0][j] == '1') {
				dp[0][j] = 1;
				maxLen = 1;
			}
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				if (matrix[i][j] == '1') {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
					maxLen = max(dp[i][j], maxLen);
				}
			}
		}
		return maxLen * maxLen;
	}
};