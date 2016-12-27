class Solution {
public:
	string getPermutation(int n, int k) {
		if (k == 0)
			return "";
		int vis[10000];
		memset(vis, 0, sizeof(vis));
		string ans;
		for (int pos = 0; pos<n - 1; pos++)
		{
			int minnum = ((k - 1) / factorial(n - 1 - pos)) % (n - pos) + 1;
			int num, i;
			char c;
			for (i = 0; i<n && minnum>0; i++)
			{
				if (vis[i] == 0)
				{
					minnum--;
					if (minnum == 0)
					{
						num = i + 1;
						c = '0' + num;
						vis[i] = 1;
					}
				}
			}
			ans.push_back(c);
		}
		for (int i = 0; i<n; i++)
			if (vis[i] == 0)
			{
				char c = '0' + i + 1;
				ans.push_back(c);
				break;
			}
		return ans;
	}
	int factorial(int k)
	{
		if (k == 0)
			return 1;
		int ans = 1;
		for (int i = 1; i <= k; i++)
			ans = ans*i;
		return ans;
	}
};