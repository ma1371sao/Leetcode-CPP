class Solution {
public:
	int firstUniqChar(string s) {
		int l = s.length();
		int num = 0;
		map<char, int> m;
		for (int i = 0; i<l; i++)
		{
			if (m.find(s[i]) == m.end())
			{
				m[s[i]] = 1;
				num++;
			}
			else if (m[s[i]] == 1)
			{
				num--;
				m[s[i]] = -1;
			}
		}
		if (num == 0)
			return -1;
		for (int i = 0; i<l; i++)
			if (m[s[i]] == 1)
				return i;
		return -1;
	}
};