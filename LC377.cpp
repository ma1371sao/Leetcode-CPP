class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		sort(nums.begin(), nums.end());
		if (nums[0] > target)
			return 0;
		vector<int> number(target + 1, 0);
		number[0] = 1;
		for (int i = nums[0]; i <= target; i++) {
			for (int j = 0; j<nums.size() && nums[j] <= i; j++) {
				number[i] += number[i - nums[j]];
			}
		}
		return number[target];
	}
};