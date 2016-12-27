class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> m;
		vector<char> v;
		int ls = s.length();
		int lt = t.length();
		for (int i = 0; i<ls; i++)
		{
			if (m.find(s[i]) != m.end())
				m[s[i]]++;
			else
			{
				m[s[i]] = 1;
				v.push_back(s[i]);
			}
		}
		for (int i = 0; i<lt; i++)
		{
			if (m.find(t[i]) == m.end())
				return false;
			m[t[i]]--;
		}
		for (int i = 0; i<v.size(); i++)
			if (m[v[i]] != 0)
				return false;
		return true;
	}
};