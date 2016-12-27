class Solution {
public:
	int findNthDigit(int n) {
		int l = 1;
		int base = 1;
		while (n - (long long)9 * base*l>0)
		{
			n = n - 9 * base*l;
			base = base * 10;
			l++;
		}
		int k = n / l;
		int p = n%l;
		int ans = base + k - 1;
		if (p == 0)
			return ans % 10;
		ans++;
		for (int i = 0; i<p - 1; i++)
		{
			ans = ans%base;
			base = base / 10;
		}
		ans = ans / base;
		return ans;
	}
};