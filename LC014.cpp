class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int l = strs.size();
		int flag = 1;
		string ans;
		if (l == 0)
			return ans;
		if (l == 1)
			return strs[0];
		string s = strs[0];
		int ls = s.size();
		for (int j = 0; j<ls; j++)
		{
			for (int i = 1; i<l; i++)
			{
				if (s[j] != strs[i][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				ans.push_back(s[j]);
			}
			else
				break;
		}
		return ans;
	}
};