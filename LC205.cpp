class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int l = s.length();
		map<char, char> m;
		map<char, int> vis;
		for (int i = 0; i<l; i++)
		{
			if (m.find(s[i]) == m.end())
			{
				if (vis.find(t[i]) == vis.end())
				{
					vis[t[i]] = 1;
					m[s[i]] = t[i];
				}
				else
					return false;
			}
			else
			{
				if (m[s[i]] != t[i])
					return false;
			}
		}
		return true;
	}
};