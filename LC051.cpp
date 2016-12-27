class Solution {
public:
	int vis[1000];
	int col[1000];
	vector<vector<string>> ans;
	map<int, int> pm;
	map<int, int> nm;
	vector<vector<string>> solveNQueens(int n) {
		if (n == 0)
			return ans;
		memset(vis, 0, sizeof(vis));
		memset(col, 0, sizeof(col));
		DFS(n, 0);
		return ans;
	}
	void DFS(int n, int row)
	{
		if (row == n)
		{
			vector<string> v;
			for (int r = 0; r<n; r++)
			{
				string s;
				for (int c = 0; c<n; c++)
				{
					if (c == col[r])
						s.push_back('Q');
					else
						s.push_back('.');
				}
				v.push_back(s);
			}
			ans.push_back(v);
			return;
		}
		for (int c = 0; c<n; c++)
		{
			if (vis[c])
				continue;
			else
			{
				int b1 = -row - c;
				int b2 = -row + c;
				if (pm[b1] == 0 && nm[b2] == 0)
				{
					vis[c] = 1;
					col[row] = c;
					pm[b1] = 1;
					nm[b2] = 1;
					DFS(n, row + 1);
					vis[c] = 0;
					pm[b1] = 0;
					nm[b2] = 0;
				}
			}
		}
	}
};