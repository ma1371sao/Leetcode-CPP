class Solution {
public:
	int romanToInt(string s) {
		int l = s.size();
		int M, D, C, L, X, V;
		int res = 0;
		map<char, int> m;
		m.insert(pair<char, int>('M', 1000));
		m.insert(pair<char, int>('D', 500));
		m.insert(pair<char, int>('C', 100));
		m.insert(pair<char, int>('L', 50));
		m.insert(pair<char, int>('X', 10));
		m.insert(pair<char, int>('V', 5));
		m.insert(pair<char, int>('I', 1));
		for (int i = 0; i<l - 1; i++)
		{
			if (m[s[i]] >= m[s[i + 1]])
				res = res + m[s[i]];
			else
				res = res - m[s[i]];
		}
		res = res + m[s[l - 1]];
		return res;
	}
};