class Solution {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.length();
		int n2 = num2.length();
		int i, j;
		string ans;
		int flag = 0;
		if (n1 == 0 || n2 == 0)
			return ans;
		if ((n1 == 1 && num1[0] == '0') || (n2 == 1 && num2[0] == '0'))
		{
			ans.push_back('0');
			return ans;
		}
		for (i = n1 - 1; i >= 0; i--)
		{
			string s;
			flag = 0;
			for (int k = n1 - 1 - i; k>0; k--)
				s.push_back('0');
			for (j = n2 - 1; j >= 0; j--)
			{
				int tmp = (num1[i] - '0')*(num2[j] - '0') + flag;
				flag = tmp / 10;
				s.push_back(tmp % 10 + '0');
			}
			s.push_back(flag + '0');
			//plus
			if (i == n1 - 1)
				ans = s;
			else
			{
				flag = 0;
				int p = 0;
				int q = 0;
				while (p<s.length() || q<ans.length())
				{
					if (p<s.length() && q<ans.length())
					{
						int tmp = s[p] - '0' + ans[q] - '0' + flag;
						ans[q] = tmp % 10 + '0';
						flag = tmp / 10;
						p++;
						q++;
					}
					else if (q<ans.length() && p == s.length())
					{
						int tmp = ans[q] - '0' + flag;
						ans[q] = tmp % 10 + '0';
						flag = tmp / 10;
						q++;
					}
					else if (p<s.length() && q == ans.length())
					{
						int tmp = s[p] - '0' + flag;
						ans.push_back(tmp % 10 + '0');
						flag = tmp / 10;
						p++;
					}
				}
				if (flag)
					ans.push_back(flag + '0');
			}
		}
		string res;
		for (int i = ans.length() - 1; i >= 0; i--)
			res.push_back(ans[i]);
		int k;
		for (k = 0; k<res.length() && res[k] == '0'; k++);
		return res.substr(k);
	}
};