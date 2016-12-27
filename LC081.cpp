class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0)    return false;
		int dis = 0;
		for (int i = n - 1; i>0; i--)
			if (nums[i]<nums[i - 1]) {
				dis = i;
				break;
			}
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[(mid + dis) % n] == target)
				return true;
			if (nums[(mid + dis) % n]>target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return false;
	}
};