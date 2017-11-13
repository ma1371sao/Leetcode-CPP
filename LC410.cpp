class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		long sum = 0;
		int maxNum = 0;
		for (int num : nums) {
			sum += num;
			maxNum = max(maxNum, num);
		}
		if (m == 1) return (int)sum;
		long l = maxNum;
		long r = sum;
		while (l <= r) {
			long mid = l + (r - l) / 2;
			if (valid(nums, m, mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		return l;
	}

	bool valid(vector<int>& nums, int m, long target) {
		int count = 1;
		long sum = 0;
		for (int num : nums) {
			sum += num;
			if (sum > target) {
				sum = num;
				count++;
				if (count > m)
					return false;
			}
		}
		return true;
	}
};