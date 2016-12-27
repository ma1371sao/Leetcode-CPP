class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		if (n == 0)
			return 0;
		int ans[100][100];
		int flag = 0;
		for (int i = 0; i<n; i++)
		{
			if (obstacleGrid[0][i] == 1)
				flag = 1;
			if (flag)
				ans[0][i] = 0;
			else
				ans[0][i] = 1;
		}
		flag = 0;
		for (int i = 0; i<m; i++)
		{
			if (obstacleGrid[i][0] == 1)
				flag = 1;
			if (flag)
				ans[i][0] = 0;
			else
				ans[i][0] = 1;
		}
		for (int r = 1; r<m; r++)
			for (int c = 1; c<n; c++)
				if (!obstacleGrid[r][c])
					ans[r][c] = ans[r - 1][c] + ans[r][c - 1];
				else
					ans[r][c] = 0;
		return ans[m - 1][n - 1];
	}
};