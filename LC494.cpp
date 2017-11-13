class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		int target = sum + S;
		if (target % 2 || sum < S) return 0;
		target /= 2;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int num : nums) {
			for (int i = target; i >= num; i--) {
				dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}
};