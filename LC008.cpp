class Solution {
public:
	int myAtoi(string str) {
		int res = 0, flag = 1;
		int l = str.size();
		int r[1000], k = 0, i = 0;
		if (str == "")
			return res;
		for (; str[i] == ' ' || str[i] == '\n' || str[i] == '\t'; i++)
			if (i == l)
				return res;
		if (str[i] == '-')
		{
			flag = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		for (; i<l && str[i] >= '0' && str[i] <= '9'; i++)
		{
			if (flag>0 && res>((INT_MAX - (str[i] - 48)) / 10) || flag<0 && flag*res<(INT_MIN + (str[i] - 48)) / 10)
			{
				if (flag>0)
				{
					res = INT_MAX;
					return res;
				}
				else
				{
					res = INT_MIN;
					return res;
				}
			}
			res = res * 10 + str[i] - 48;
		}
		res = res*flag;
		return res;
	}
};