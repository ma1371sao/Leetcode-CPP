class Solution {
public:
	bool isMatch(string s, string p) {
		int ls = s.length();
		int lp = p.length();
		if (ls == 0)
		{
			if (lp == 0)
				return true;
			else if (p[1] == '*')
			{
				if (isMatch(s, p.substr(2)))
					return true;
				else
					return false;
			}
			else
				return false;
		}
		if (lp == 0)
			return false;
		if (s[0] == p[0] || p[0] == '.')
		{
			if (p[1] == '*')
				if (isMatch(s.substr(1), p))
					return true;
				else
				{
					if (isMatch(s, p.substr(2)))
						return true;
					else
						return false;
				}
			else
				if (isMatch(s.substr(1), p.substr(1)))
					return true;
				else
					return false;
		}
		else
		{
			if (p[1] == '*')
				if (isMatch(s, p.substr(2)))
					return true;
				else
					return false;
			else
				return false;
		}
		return true;
	}
};