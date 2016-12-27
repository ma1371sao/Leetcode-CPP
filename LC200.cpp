class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0)
			return 0;
		int col = grid[0].size();
		int ans = 0;
		int vis[1000][1000];
		for (int i = 0; i<row; i++)
			memset(vis[i], 0, sizeof(vis[i]));
		for (int r = 0; r<row; r++)
			for (int c = 0; c<col; c++)
			{
				if (grid[r][c] == '1' && !vis[r][c])
				{
					ans++;
					vis[r][c] = 1;
					search(r, c, vis, grid, row, col);
				}
			}
		return ans;
	}
	void search(int r, int c, int vis[][1000], vector<vector<char>>& grid, int row, int col)
	{
		if (r>0 && grid[r - 1][c] == '1' && !vis[r - 1][c])
		{
			vis[r - 1][c] = 1;
			search(r - 1, c, vis, grid, row, col);
		}
		if (c>0 && grid[r][c - 1] == '1' && !vis[r][c - 1])
		{
			vis[r][c - 1] = 1;
			search(r, c - 1, vis, grid, row, col);
		}
		if (r + 1<row && grid[r + 1][c] == '1' && !vis[r + 1][c])
		{
			vis[r + 1][c] = 1;
			search(r + 1, c, vis, grid, row, col);
		}
		if (c + 1<col && grid[r][c + 1] == '1' && !vis[r][c + 1])
		{
			vis[r][c + 1] = 1;
			search(r, c + 1, vis, grid, row, col);
		}
	}
};