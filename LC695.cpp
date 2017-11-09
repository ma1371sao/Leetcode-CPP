class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		int maxArea = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j]) {
					int area = 0;
					dfs(i, j, grid, area);
					if (area > maxArea) maxArea = area;
				}
			}
		}
		return maxArea;
	}

	void dfs(int r, int c, vector<vector<int>>& grid, int& area) {
		int row = grid.size();
		int col = grid[0].size();
		grid[r][c] = 0;
		area++;
		if (r > 0 && grid[r - 1][c]) dfs(r - 1, c, grid, area);
		if (r < row - 1 && grid[r + 1][c]) dfs(r + 1, c, grid, area);
		if (c > 0 && grid[r][c - 1]) dfs(r, c - 1, grid, area);
		if (c < col - 1 && grid[r][c + 1]) dfs(r, c + 1, grid, area);
	}
};