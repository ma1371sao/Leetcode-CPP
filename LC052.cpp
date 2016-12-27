class Solution {
public:
	int ans;
	int vis[1000];
	map<int, int> pm;
	map<int, int> nm;
	int totalNQueens(int n) {
		if (n == 0)
			return 0;
		ans = 0;
		memset(vis, 0, sizeof(vis));
		DFS(n, 0);
		return ans;
	}
	void DFS(int n, int row)
	{
		if (row == n)
		{
			ans++;
			return;
		}
		for (int c = 0; c<n; c++)
		{
			if (vis[c] == 1)
				continue;
			int b1 = -row - c;
			int b2 = -row + c;
			if (pm[b1] == 0 && nm[b2] == 0)
			{
				vis[c] = 1;
				pm[b1] = 1;
				nm[b2] = 1;
				DFS(n, row + 1);
				vis[c] = 0;
				pm[b1] = 0;
				nm[b2] = 0;
			}
		}
	}
};