class Solution {
public:
	int trailingZeroes(int n) {
		int b = 0;
		if (n == 0)
			return 0;
		while (n / 5 != 0)
		{
			n = n / 5;
			b = b + n; a
		}
		return b;
	}
};