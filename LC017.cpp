class Solution {
public:
	vector<string> ans;
	int n;
	char sans[1000000];
	map<char, string> m;
	vector<string> letterCombinations(string digits) {
		m['2'] = "abc";
		m['3'] = "def";
		m['4'] = "ghi";
		m['5'] = "jkl";
		m['6'] = "mno";
		m['7'] = "pqrs";
		m['8'] = "tuv";
		m['9'] = "wxyz";
		n = digits.length();
		if (n == 0)
			return ans;
		DFS(digits, 0);
		return ans;
	}
	void DFS(string digits, int poi)
	{
		if (poi == n)
		{
			string s;
			for (int i = 0; i<poi; i++)
				if (sans[i] != ' ')
					s.push_back(sans[i]);
			ans.push_back(s);
		}
		if (digits[poi] == '1')
		{
			sans[poi] = ' ';
			DFS(digits, poi + 1);
		}
		else
		{
			string str = m[digits[poi]];
			for (int i = 0; i<str.length(); i++)
			{
				sans[poi] = str[i];
				DFS(digits, poi + 1);
			}
		}
	}
};