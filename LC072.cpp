class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
		for (int i = 0; i < word2.length(); i++) {
			dp[0][i + 1] = i + 1;
		}
		for (int i = 0; i < word1.length(); i++) {
			dp[i + 1][0] = i + 1;
		}
		for (int r = 0; r < word1.length(); r++) {
			for (int c = 0; c < word2.length(); c++) {
				if (word1[r] == word2[c])
					dp[r + 1][c + 1] = dp[r][c];
				else {
					dp[r + 1][c + 1] = min(dp[r][c + 1], dp[r][c]);
					dp[r + 1][c + 1] = min(dp[r + 1][c + 1], dp[r + 1][c]);
					dp[r + 1][c + 1] += 1;
				}
			}
		}
		return dp[word1.length()][word2.length()];
	}
};