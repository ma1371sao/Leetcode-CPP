class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0)  return 0;
		int col = grid[0].size();
		if (col == 0)  return 0;
		int res = 0;
		for (int r = 0; r<row; r++) {
			for (int c = 0; c<col; c++) {
				if (grid[r][c]) {
					if (r == 0)    res++;
					else if (!grid[r - 1][c])   res++;
					if (r == row - 1)    res++;
					else if (!grid[r + 1][c])  res++;
					if (c == 0)    res++;
					else if (!grid[r][c - 1])  res++;
					if (c == col - 1)    res++;
					else if (!grid[r][c + 1])  res++;
				}
			}
		}
		return res;
	}
};