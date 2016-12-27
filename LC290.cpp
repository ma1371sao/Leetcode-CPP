class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int lp = pattern.length();
		int ls = str.length();
		int start = 0, end = 0;
		vector<string> s;
		for (end = 0; end<ls; end++)
			if (str[end] == ' ')
			{
				s.push_back(str.substr(start, end - start));
				start = end + 1;
			}
		s.push_back(str.substr(start, end - start));
		if (s.size() != lp)
			return false;
		map<char, string> m;
		map<string, char> ms;
		for (int i = 0; i<lp; i++)
		{
			if (m.find(pattern[i]) == m.end())
			{
				m.insert(pair<char, string>(pattern[i], s[i]));
				if (ms.find(s[i]) != ms.end())
					return false;
				else
					ms.insert(pair<string, char>(s[i], pattern[i]));
			}
			else
				if (m[pattern[i]] != s[i])
					return false;
		}
		return true;
	}
};