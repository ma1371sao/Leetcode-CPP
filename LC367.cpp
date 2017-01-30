class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num<4) {
			if (num == 1)
				return true;
			return false;
		}
		int left = 2;
		int right = num / 2;
		while (left <= right) {
			long mid = left + (right - left) / 2;
			long tmp = mid*mid;
			if (tmp == num)
				return true;
			if (tmp<num)
				left = mid + 1;
			if (tmp>num)
				right = mid - 1;
		}
		return false;
	}
};