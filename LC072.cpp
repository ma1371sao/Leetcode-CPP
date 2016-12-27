class Solution {
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size();
		int n2 = word2.size();
		if (n1 == 0)
			return n2;
		if (n2 == 0)
			return n1;
		int dp[1000][1000];
		for (int i = 0; i<n1; i++)
		{
			if (word1.substr(0, i + 1).find(word2[0]) != string::npos)
				dp[i][0] = i;
			else
				dp[i][0] = i + 1;
		}
		for (int j = 0; j<n2; j++)
		{
			if (word2.substr(0, j + 1).find(word1[0]) != string::npos)
				dp[0][j] = j;
			else
				dp[0][j] = j + 1;
		}
		for (int i = 1; i<n1; i++)
			for (int j = 1; j<n2; j++)
			{
				int upd, ins, del;
				if (word1[i] == word2[j])
					upd = dp[i - 1][j - 1];
				else
					upd = dp[i - 1][j - 1] + 1;
				del = dp[i - 1][j] + 1;
				ins = dp[i][j - 1] + 1;
				int min;
				if (upd <= del)
					min = upd;
				else
					min = del;
				if (ins<min)
					min = ins;
				dp[i][j] = min;
			}
		return dp[n1 - 1][n2 - 1];
	}
};