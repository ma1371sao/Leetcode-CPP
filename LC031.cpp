class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int l = nums.size();
		int flag = 0;
		if (nums.size() == 0 || nums.size() == 1)
			return;
		int i;
		for (i = l - 1; i >= 1 && nums[i - 1] >= nums[i]; i--);
		if (i>0)
		{
			int j;
			for (j = i + 1; j<l && nums[j]>nums[i - 1]; j++);
			int tmp = nums[j - 1];
			nums[j - 1] = nums[i - 1];
			nums[i - 1] = tmp;
			sort(nums.begin() + i, nums.end());
		}
		else
		{
			sort(nums.begin(), nums.end());
		}

	}
};