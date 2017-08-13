class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int maxLength = 1;
		vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j] && dp[j][1] + 1 > dp[i][0]) {
					dp[i][0] = dp[j][1] + 1;
				}
				if (nums[i] < nums[j] && dp[j][0] + 1 > dp[i][1]) {
					dp[i][1] = dp[j][0] + 1;
				}
			}
			if (dp[i][0] > maxLength) maxLength = dp[i][0];
			if (dp[i][1] > maxLength) maxLength = dp[i][1];
		}
		return maxLength;
	}
};