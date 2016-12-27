class Solution {
public:
	int findMin(vector<int>& nums) {
		for (int i = nums.size() - 1; i>0; i--)
			if (nums[i]<nums[i - 1])
				return nums[i];
		return nums[0];
	}
};