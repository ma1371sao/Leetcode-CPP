class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans;
		if (n == 0)
			return ans;
		int a[1000][1000];
		for (int i = 0; i<n; i++)
			memset(a, 0, sizeof(a));
		int dir = 0;
		int row, col;
		row = 0;
		col = 0;
		a[0][0] = 1;
		int num = 2;
		int r, c;
		while (num <= n*n)
		{
			if (dir == 0)
			{
				for (c = col + 1; c<n && a[row][c] == 0; c++)
					a[row][c] = num++;
				col = c - 1;
			}
			if (dir == 1)
			{
				for (r = row + 1; r<n && a[r][col] == 0; r++)
					a[r][col] = num++;
				row = r - 1;
			}
			if (dir == 2)
			{
				for (c = col - 1; c >= 0 && a[row][c] == 0; c--)
					a[row][c] = num++;
				col = c + 1;
			}
			if (dir == 3)
			{
				for (r = row - 1; r >= 0 && a[r][col] == 0; r--)
					a[r][col] = num++;
				row = r + 1;
			}
			dir = (dir + 1) % 4;
		}
		for (r = 0; r<n; r++)
		{
			vector<int> v;
			for (c = 0; c<n; c++)
				v.push_back(a[r][c]);
			ans.push_back(v);
		}
		return ans;
	}
};