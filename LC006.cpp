class Solution {
public:
	string convert(string s, int numRows) {
		int l = s.length();
		int n = numRows;
		int vis[l];
		memset(vis, 0, sizeof(vis));
		string ans;
		if (!l)
			return ans;
		if (n == 1)
		{
			ans = s;
			return ans;
		}

		for (int i = 0; i<n; i++)
		{
			for (int j = i; j<l;)
			{
				if (!vis[j])
				{
					ans.push_back(s[j]);
					vis[j] = 1;
				}
				j = j + 2 * n - 2 - 2 * i;
				if (j<l && !vis[j])
				{
					ans.push_back(s[j]);
					vis[j] = 1;
				}
				j = j + 2 * i;
				if (j<l && !vis[j])
				{
					ans.push_back(s[j]);
					vis[j] = 1;
				}
			}
		}
		return ans;
	}
};