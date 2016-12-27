class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		if (n == 0)
			return 0;
		int f[1000][1000];
		for (int r = 0; r<m; r++)
		{
			for (int c = 0; c<n; c++)
			{
				if (r == 0 && c == 0)
					f[0][0] = grid[0][0];
				else if (c == 0)
					f[r][c] = grid[r][c] + f[r - 1][c];
				else if (r == 0)
					f[r][c] = grid[r][c] + f[r][c - 1];
				else
				{
					if (f[r - 1][c] <= f[r][c - 1])
						f[r][c] = grid[r][c] + f[r - 1][c];
					else
						f[r][c] = grid[r][c] + f[r][c - 1];
				}
			}
		}
		return f[m - 1][n - 1];
	}
};