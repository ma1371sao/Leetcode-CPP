class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		int start = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] < 1 || nums[i] > n) {
				int tmp = nums[start];
				nums[start++] = nums[i];
				nums[i] = tmp;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i < start) nums[i] = 1;
			else {
				int num = abs(nums[i]);
				if (nums[num - 1] > 0)
					nums[num - 1] = -nums[num - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] > 0)
				return i + 1;
		}
		return n + 1;
	}
};