class Solution {
public:
	int nextGreaterElement(int n) {
		vector<int> nums;
		while (n) {
			nums.push_back(n % 10);
			n /= 10;
		}
		reverse(nums.begin(), nums.end());
		int pos = nums.size() - 1;
		for (; pos > 0; pos--) {
			if (nums[pos - 1] < nums[pos])
				break;
		}
		if (pos == 0) return -1;
		int min = pos;
		for (int j = pos; j < nums.size(); j++) {
			if (nums[j] > nums[pos - 1] && nums[j] < nums[min])
				min = j;
		}
		int temp = nums[pos - 1];
		nums[pos - 1] = nums[min];
		nums[min] = temp;
		sort(nums.begin() + pos, nums.end());
		long long res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += nums[i] * pow(10, nums.size() - 1 - i);
		}
		if (res > INT_MAX) return -1;
		return res;
	}
};