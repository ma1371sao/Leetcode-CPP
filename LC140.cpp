class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> ans;
		int n = s.length();
		if (n == 0)
			return ans;
		int dp[10000];
		memset(dp, 0, sizeof(dp));
		vector<vector<int>> breakp;
		for (int i = 0; i<n; i++)
		{
			vector<int> v;
			breakp.push_back(v);
		}
		for (int i = 0; i<n; i++)
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
			{
				dp[i] = 1;
				breakp[i].push_back(-1);
			}
		for (int i = 1; i<n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (dp[j])
				{
					if (wordDict.find(s.substr(j + 1, i - j)) != wordDict.end())
					{
						dp[i] = 1;
						breakp[i].push_back(j);
					}
				}
			}
		}
		if (!dp[n - 1])
			return ans;
		vector<int> path;
		path.push_back(n - 1);
		DFS(ans, s, wordDict, breakp, dp, n - 1, path);
		return ans;
	}
	void DFS(vector<string>& ans, string s, unordered_set<string>& wordDict, vector<vector<int>>& breakp, int *dp, int pos, vector<int>& path)
	{
		if (pos == -1)
		{
			string str;
			for (int i = path.size() - 2; i >= 0; i--)
			{
				if (i != path.size() - 2)
					str = str + " ";
				str = str + s.substr(path[i + 1] + 1, path[i] - path[i + 1]);
			}
			ans.push_back(str);
			return;
		}
		for (int i = 0; i<breakp[pos].size(); i++)
		{
			path.push_back(breakp[pos][i]);
			DFS(ans, s, wordDict, breakp, dp, breakp[pos][i], path);
			path.pop_back();
		}
	}
};