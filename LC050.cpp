class Solution {
public:
	double myPow(double x, int n) {
		if (n == 1)
			return x;
		if (n == 0)
			return 1;
		if (n == -1)
			return 1.0 / x;
		double sub = myPow(x, n / 2);
		return sub*sub*myPow(x, n % 2);
	}
};