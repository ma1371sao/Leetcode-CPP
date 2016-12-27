class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0)
			return 1;
		sort(nums.begin(), nums.end());
		int ans;
		for (ans = 0; ans<nums.size() && nums[ans] <= 0; ans++);
		if (nums[ans] != 1 || ans == nums.size())
			return 1;
		int i = ans;
		for (ans = 1; i<nums.size() && ans == nums[i]; i++, ans++)
			while (i + 1<nums.size() && ans == nums[i + 1])
				i++;
		return ans;
	}
};