class Solution {
public:
	int reverse(int x) {
		int flag = 1;
		if (x<0)
		{
			flag = -1;
			x = -x;
		}
		int l = 0, a = x, res = 0, r[1000];
		do
		{
			r[l++] = a % 10;
			a = a / 10;
		} while (a);
		for (int i = l - 1; i >= 0; i--)
		{
			res = res + r[i] * pow(10, l - 1 - i);
			if (res<0)
			{
				res = 0;
				break;
			}
		}
		res = res*flag;
		return res;
	}
};