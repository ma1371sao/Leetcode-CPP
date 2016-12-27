class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return true;
		return DFS(nums, nums[0], 0);
	}
	bool DFS(vector<int>& nums, int pos, int start)
	{
		if (pos >= nums.size() - 1)
			return true;
		int max = pos + nums[pos];
		int s = pos;
		for (int j = pos - 1; j>start; j--)
		{
			if (max<nums[j] + j)
			{
				max = nums[j] + j;
				s = j;
			}
		}
		if (max>pos)
			if (DFS(nums, max, s))
				return true;
		return false;
	}
};