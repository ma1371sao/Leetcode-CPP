class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
		for (int i = 1; i <= 2; i++) {
			int maxVal = dp[i - 1][0] - prices[0];
			for (int j = 1; j < prices.size(); j++) {
				dp[i][j] = max(dp[i][j - 1], prices[j] + maxVal);
				maxVal = max(maxVal, dp[i - 1][j] - prices[j]);
			}
		}
		return dp[2][prices.size() - 1];
	}
};