class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() <= 1 || k == 0) return 0;
		if (k > prices.size() / 2) {
			int ans = 0;
			for (int i = 1; i < prices.size(); i++) {
				ans += max(prices[i] - prices[i - 1], 0);
			}
			return ans;
		}
		vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
		for (int i = 1; i <= k; i++) {
			int maxTmp = dp[k - 1][0] - prices[0];
			for (int j = 1; j < prices.size(); j++) {
				dp[i][j] = max(dp[i][j - 1], maxTmp + prices[j]);
				maxTmp = max(maxTmp, dp[i - 1][j] - prices[j]);
			}
		}
		return dp[k][prices.size() - 1];
	}
};