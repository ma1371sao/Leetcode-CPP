class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (sum % 2) return false;
		int mid = sum / 2;
		vector<int> dp(mid + 1, INT_MIN);
		dp[0] = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int num = mid; num >= nums[i]; num--) {
				dp[num] = max(dp[num], dp[num - nums[i]] + 1);
			}
		}
		if (dp[mid] < 0) return false;
		return true;
	}
};