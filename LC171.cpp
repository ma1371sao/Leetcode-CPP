class Solution {
public:
	int titleToNumber(string s) {
		int l = s.length();
		int ans = 0;
		for (int i = 0; i<l; i++)
		{
			ans = ans + (s[i] - 'A' + 1)*pow(26, l - i - 1);
		}
		return ans;
	}
};