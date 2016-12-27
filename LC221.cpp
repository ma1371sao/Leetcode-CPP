class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (!row)    return 0;
		int col = matrix[0].size();
		if (!col)    return 0;
		int dp[1000][1000];
		int ans = 0;
		for (int i = 0; i<row; i++)
			memset(dp[i], 0, sizeof(dp[i]));
		for (int i = 0; i<row; i++)
			if (matrix[i][0] == '1')
			{
				ans = 1;
				dp[i][0] = 1;
			}
		for (int i = 0; i<col; i++)
			if (matrix[0][i] == '1')
			{
				dp[0][i] = 1;
				ans = 1;
			}
		for (int r = 1; r<row; r++)
			for (int c = 1; c<col; c++)
			{
				if (matrix[r][c] == '1')
				{
					int min = dp[r - 1][c];
					if (dp[r][c - 1]<min)
						min = dp[r][c - 1];
					if (dp[r - 1][c - 1]<min)
						min = dp[r - 1][c - 1];
					dp[r][c] = min + 1;
					if (dp[r][c]>ans)
						ans = dp[r][c];
				}
			}
		return ans*ans;
	}
};