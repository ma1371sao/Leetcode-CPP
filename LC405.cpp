class Solution {
public:
	string toHex(int num) {
		string ans;
		map<int, char> m;
		for (int i = 0; i<10; i++)
			m[i] = '0' + i;
		for (int i = 10; i<16; i++)
			m[i] = 'a' + i - 10;
		if (num == 0)
		{
			ans.push_back('0');
		}
		else if (num>0)
		{
			string s;
			while (num)
			{
				int c = num % 16;
				num = num / 16;
				s.push_back(m[c]);
			}
			for (int i = s.length() - 1; i >= 0; i--)
				ans.push_back(s[i]);
		}
		else
		{
			if (num == INT_MIN)
				return "80000000";
			string s;
			int tmp = -num;
			vector<int> binary;
			while (tmp)
			{
				int c = tmp % 2;
				tmp = tmp / 2;
				binary.push_back(c);
			}
			for (int i = binary.size(); i<31; i++)
				binary.push_back(0);
			for (int i = 0; i<31; i++)
				if (binary[i] == 0)
					binary[i] = 1;
				else
					binary[i] = 0;
			int jinwei = 1;
			for (int i = 0; i<31 && jinwei; i++)
			{
				if (binary[i] == 0)
				{
					binary[i] = 1;
					jinwei = 0;
				}
				else
				{
					binary[i] = 0;
					jinwei = 1;
				}
			}
			if (jinwei)
				binary.push_back(0);
			else
				binary.push_back(1);
			for (int i = 0; i<8; i++)
			{
				int p = 0;
				for (int y = i * 4; y<(i + 1) * 4; y++)
				{
					p = p + binary[y] * pow(2, (y - i * 4));
				}
				s.push_back(m[p]);
			}
			for (int i = s.length() - 1; i >= 0; i--)
				ans.push_back(s[i]);

		}
		return ans;
	}
};