class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		if (row == 0)  return 0;
		vector<int> dp(row + 1, 0);
		dp[0] = triangle[0][0];
		int backup = dp[0];
		for (int r = 1; r<row; r++) {
			for (int c = 0; c<r + 1; c++) {
				if (c == 0) {
					backup = dp[c];
					dp[c] = triangle[r][c] + dp[c];
				}
				else if (c == r)
					dp[c] = triangle[r][c] + backup;
				else {
					int min = backup;
					backup = dp[c];
					if (min>dp[c])
						min = dp[c];
					dp[c] = triangle[r][c] + min;
				}
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i<row; i++)
			if (dp[i]<ans)
				ans = dp[i];
		return ans;
	}
};