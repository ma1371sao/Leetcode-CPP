class Solution {
public:
	vector<string> ans;
	int number[10];
	vector<string> readBinaryWatch(int num) {
		number[0] = 1;
		number[1] = 2;
		number[2] = 4;
		number[3] = 8;
		number[4] = 1;
		number[5] = 2;
		number[6] = 4;
		number[7] = 8;
		number[8] = 16;
		number[9] = 32;
		back(num, 0, 0, 0);
		return ans;
	}
	void back(int num, int k, int h, int min)
	{
		if (num == 0)
		{
			string s;
			if (h<10)
			{
				char c = h + 48;
				s.push_back(c);
				s.push_back(':');
			}
			else
			{
				char c1 = h / 10 + 48;
				char c2 = h % 10 + 48;
				s.push_back(c1);
				s.push_back(c2);
				s.push_back(':');
			}
			if (min<10)
			{
				s.push_back('0');
				char c = min + 48;
				s.push_back(c);
			}
			else
			{
				char c1 = min / 10 + 48;
				char c2 = min % 10 + 48;
				s.push_back(c1);
				s.push_back(c2);
			}
			ans.push_back(s);
			return;
		}
		if (k == 10)
			return;
		if (k<4)
		{
			if (h + number[k]<12)
				back(num - 1, k + 1, h + number[k], min);
		}
		else
		{
			if (min + number[k]<60)
				back(num - 1, k + 1, h, min + number[k]);
		}
		back(num, k + 1, h, min);
	}
};