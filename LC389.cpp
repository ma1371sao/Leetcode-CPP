class Solution {
public:
	char findTheDifference(string s, string t) {
		int ls = s.length();
		int lt = ls + 1;
		map<char, int> m;
		for (int i = 0; i<ls; i++)
		{
			if (m.find(s[i]) == m.end())
				m[s[i]] = 1;
			else
				m[s[i]]++;
		}
		for (int i = 0; i<lt; i++)
		{
			if (m.find(t[i]) == m.end())
				return t[i];
			else
			{
				m[t[i]]--;
			}
		}
		for (int i = 0; i<ls; i++)
			if (m[s[i]] != 0)
				return s[i];
		return 0;
	}
};