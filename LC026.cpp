class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int l = nums.size();
		int n_l = l;
		if (l == 0)
			return n_l;
		unique(nums.begin(), nums.end());
		for (int i = 0; i<l - 1; i++)
			if (nums[i] >= nums[i + 1])
			{
				n_l = i + 1;
				break;
			}
		return n_l;
	}
};