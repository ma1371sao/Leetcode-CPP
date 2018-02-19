class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; k++) {
            int profitAtBuy = dp[k - 1][0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[k][i] = max(dp[k][i - 1], prices[i] + profitAtBuy);
                profitAtBuy = max(profitAtBuy, dp[k - 1][i - 1] - prices[i]);
            }
        }
        return dp[2][prices.size() - 1];
    }
};
