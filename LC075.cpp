class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return;
		qsort(0, n - 1, nums);
	}
	void qsort(int left, int right, vector<int>& nums)
	{
		if (left<right)
		{
			int i = left;
			int j = right;
			do
			{
				for (i = i + 1; i<right && nums[i]<nums[left]; i++);
				for (; j>left && nums[j]>nums[left]; j--);
				if (i<j)
				{
					int tmp = nums[i];
					nums[i] = nums[j];
					nums[j] = tmp;
				}
			} while (i<j);
			if (j>left)
			{
				int tmp = nums[left];
				nums[left] = nums[j];
				nums[j] = tmp;
			}
			qsort(left, j - 1, nums);
			qsort(j + 1, right, nums);
		}
	}
};