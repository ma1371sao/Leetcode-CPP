class Solution {
public:
	int arrangeCoins(int n) {
		int res = 0;
		for (int i = 1; n >= 0; i++) {
			n -= i;
			if (n >= 0) res++;
		}
		return res;
	}
};