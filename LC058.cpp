class Solution {
public:
	int lengthOfLastWord(string s) {
		int l = s.length();
		if (!l)
			return 0;
		int start = 0, end = -1, flag = 0;
		for (int i = l - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
				if (flag == 1)
				{
					start = i + 1;
					break;
				}
				else
					continue;
			else
			{
				if (flag == 0)
				{
					flag = 1;
					end = i;
				}
			}
		}
		if (!flag)
			return 0;
		return end - start + 1;
	}
};