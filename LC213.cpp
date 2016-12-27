class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)  return 0;
		if (nums.size() == 1)  return nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		if (nums[1] >= nums[0])    dp[1] = nums[1];
		else dp[1] = nums[0];
		for (int i = 2; i<nums.size() - 1; i++) {
			if (nums[i] + dp[i - 2] >= dp[i - 1])
				dp[i] = nums[i] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
		}
		int res = dp[nums.size() - 2];
		dp[0] = 0;
		dp[1] = nums[1];
		for (int i = 2; i<nums.size(); i++) {
			if (nums[i] + dp[i - 2] >= dp[i - 1])
				dp[i] = nums[i] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
		}
		if (res >= dp[nums.size() - 1])
			return res;
		else
			return dp[nums.size() - 1];
	}
};