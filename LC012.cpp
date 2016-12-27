class Solution {
public:
	string intToRoman(int num) {
		string ans;
		char c[7] = { 'I','V','X','L','C','D','M' };
		int scale = 1000;
		for (int i = 6; i >= 0; i = i - 2)
		{
			int t = num / scale;
			if (t == 1 || t == 2 || t == 3)
			{
				for (int j = 0; j<t; j++)
					ans.push_back(c[i]);
			}
			if (t == 4)
			{
				ans.push_back(c[i]);
				ans.push_back(c[i + 1]);
			}
			if (t == 5)
				ans.push_back(c[i + 1]);
			if (t == 6 || t == 7 || t == 8)
			{
				ans.push_back(c[i + 1]);
				for (int j = 0; j<t - 5; j++)
					ans.push_back(c[i]);
			}
			if (t == 9)
			{
				ans.push_back(c[i]);
				ans.push_back(c[i + 2]);
			}
			num = num%scale;
			scale = scale / 10;
		}
		return ans;
	}
};