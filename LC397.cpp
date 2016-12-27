class Solution {
public:
	int ans = INT_MAX;
	int integerReplacement(int n) {
		if (n == ans)
			return 32;
		count(n, 0);
		return ans;
	}
	void count(int n, int c)
	{
		if (n == 1)
		{
			if (c<ans)
				ans = c;
			return;
		}
		if (n % 2 == 0)
		{
			count(n / 2, c + 1);
		}
		else
		{
			count(n + 1, c + 1);
			count(n - 1, c + 1);
		}
	}
};