class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.length();
		if (n == 0)
			return false;
		int dp[10000];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i<n; i++)
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
				dp[i] = 1;
		for (int i = 1; i<n; i++)
		{
			if (dp[i] == 0)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (dp[j])
					{
						if (wordDict.find(s.substr(j + 1, i - j)) != wordDict.end())
						{
							dp[i] = 1;
							break;
						}
					}
				}
			}
		}
		if (dp[n - 1])
			return true;
		return false;
	}
};