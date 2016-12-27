class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		long long left = 1;
		long long right = x;
		long long mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (mid*mid == x)
				return mid;
			if (mid*mid<x)
			{
				left = mid + 1;
			}
			if (mid*mid>x)
			{
				right = mid - 1;
			}
		}
		return right;
	}
};