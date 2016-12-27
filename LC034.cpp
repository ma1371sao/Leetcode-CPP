class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == target)
				break;
			if (nums[mid]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if (nums[mid] == target)
		{
			int end, start;
			for (end = mid; end <= right && nums[end] == target; end++);
			end--;
			for (start = mid; start >= left && nums[start] == target; start--);
			start++;
			ans.push_back(start);
			ans.push_back(end);
			return ans;
		}
		ans.push_back(-1);
		ans.push_back(-1);
		return ans;
	}
};