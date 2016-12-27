class Solution {
public:
	int divide(int dividend, int divisor) {
		int ans = 0;
		int flag = 0;
		if (dividend == 0x80000000 && divisor == -1)
			return 0x7fffffff;
		if (dividend == 0)
			return 0;
		if ((dividend<0 && divisor<0) || (dividend>0 && divisor>0))
			flag = 1;
		else
			flag = -1;
		long long did = llabs((long long)dividend);
		long long dir = llabs((long long)divisor);
		long long a[100000];
		a[0] = dir;
		int max;
		for (max = 0; a[max] <= did; max++)
		{
			dir = dir << 1;
			a[max + 1] = dir;
		}
		long long cur = 0;
		for (int i = max - 1; i >= 0; i--)
		{
			while (cur + a[i] <= did)
			{
				cur = cur + a[i];
				ans = ans + pow(2, i);
			}
		}
		if (flag == 1)
			return ans;
		if (flag == -1)
			return -ans;
		return ans;
	}
};