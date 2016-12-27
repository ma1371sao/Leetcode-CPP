class Solution {
public:
	string addBinary(string a, string b) {
		int la = a.length();
		int lb = b.length();
		if (la<lb)
		{
			string temp = a;
			a = b;
			b = temp;
			la = a.length();
			lb = b.length();
		}
		string ans;
		int flag = 0;
		for (int i = la - 1, j = lb - 1; i >= 0; i--, j--)
		{
			if (j >= 0)
			{
				int temp = a[i] - 48 + b[j] - 48 + flag;
				if (temp>1)
				{
					temp = temp % 2;
					flag = 1;
				}
				else
					flag = 0;
				ans.push_back(temp + 48);
			}
			else
			{
				int temp = a[i] - 48 + flag;
				if (temp>1)
				{
					temp = temp % 2;
					flag = 1;
				}
				else
					flag = 0;
				ans.push_back(temp + 48);
			}
		}
		if (flag)
			ans.push_back(flag + 48);
		int al = ans.length();
		string res;
		for (int i = al - 1; i >= 0; i--)
			res.push_back(ans[i]);
		return res;
	}
};