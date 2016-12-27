class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0 || k == 0 || k>n)
			return n;
		for (int i = 0; i<k; i++)
		{
			for (int j = n - 1; j>i; j--)
				if (nums[j]>nums[j - 1])
				{
					int tmp = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = tmp;
				}
		}
		return nums[k - 1];
	}
};