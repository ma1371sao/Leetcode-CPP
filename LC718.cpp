class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int na = A.size();
		int nb = B.size();
		int maxLen = 0;
		vector<vector<int>> dp(na, vector<int>(nb, 0));
		for (int i = 0; i < na; i++) {
			if (B[0] == A[i])
				dp[i][0] = 1;
		}
		for (int i = 0; i < nb; i++) {
			if (B[i] == A[0])
				dp[0][i] = 1;
		}
		for (int i = 1; i < nb; i++)
			for (int j = 1; j < na; j++) {
				if (A[i] == B[j])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				if (dp[i][j] > maxLen)
					maxLen = dp[i][j];
			}
		return maxLen;
	}
};