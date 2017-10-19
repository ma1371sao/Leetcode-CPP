class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int maxSum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			if (maxSum < dp[i])
				maxSum = dp[i];
		}
		return maxSum;
	}
};