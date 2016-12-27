class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		int n = nums.size();
		int poi = 0;
		for (; poi<n - 1 && nums[poi]<nums[poi + 1]; poi++);
		int num = poi + 1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[(mid + num) % n] == target)
				return (mid + num) % n;
			if (nums[(mid + num) % n]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;
	}
};