class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return 0;
		int target = nums.size() - 1;
		int scale[1000000];
		scale[0] = 0;
		int jump;
		for (jump = 1;; jump++)
		{
			int max = scale[jump - 1];
			for (int i = jump - 1; i <= scale[jump - 1]; i++)
			{
				int tmp = nums[i] + i;
				if (tmp>max)
					max = tmp;
			}
			scale[jump] = max;
			if (max >= target)
				break;
		}
		return jump;
	}
};