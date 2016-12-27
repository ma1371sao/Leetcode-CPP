class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left, right;
		left = 0;
		if (nums.size() == 0)
			return 0;
		right = nums.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			if (left == right)
			{
				if (nums[mid]<target)
					return (mid + 1);
				else
					return mid;
			}
			if (nums[mid]>target)
			{
				right = mid - 1;
			}
			if (nums[mid]<target)
			{
				left = mid + 1;
			}
		}
		return left;
	}
};