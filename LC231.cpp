class Solution {
public:
	bool isPowerOfTwo(int n) {
		int tmp = n;
		if (n == 0)
			return false;
		if (n == 1)
			return true;
		while (tmp % 2 == 0)
		{
			tmp = tmp / 2;
		}
		if (tmp == 1)
			return true;
		return false;
	}
};