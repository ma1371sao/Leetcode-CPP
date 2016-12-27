class Solution {
public:
	int flag = 0;
	bool isMatch(string s, string p) {
		string ss;
		for (int i = 0; i<p.length(); i++)
			if (p[i] != '*')
				ss.push_back(p[i]);
			else
			{
				ss.push_back('*');
				for (; i<p.length() && p[i] == '*'; i++);
				i--;
			}
		return DFS(s, ss);
	}
	bool DFS(string s, string p)
	{
		if (s.length() == 0 && p.length() == 0)
			return true;
		else if (p.length() == 0)
			return false;
		else if (s.length() == 0)
		{
			if (p[0] == '*')
			{
				if (p.length() == 1)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		if (p[0] != '*')
		{
			int i = 0;
			for (; i<p.length() && i<s.length() && (p[i] == s[i] || p[i] == '?'); i++);
			if (i<p.length() && i<s.length() && p[i] != s[i] && p[i] != '*')
				return false;
			else
				if (DFS(s.substr(i), p.substr(i)))
					return true;
				else
					return false;

		}
		else
		{
			if (p.length() == 1)
				return true;
			for (int i = 0; i <= s.length(); i++)
			{
				if (DFS(s.substr(i), p.substr(1)))
					return true;
				else if (flag)
					return false;
			}
			flag = 1;
		}
		return false;
	}
};