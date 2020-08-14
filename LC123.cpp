//DP
class Solution1 {
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

//Divide and conquer
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int maxPft = 0;
        int minP = prices[0];
        vector<int> maxPftLeft(n, 0);
        vector<int> maxPftRight(n, 0);
        for (int i = 1; i < n; i++) {
            if (prices[i] > minP)
                maxPft = max(maxPft, prices[i] - minP);
            else
                minP = prices[i];
            maxPftLeft[i] = maxPft;
        }
        
        int maxP = prices[n - 1];
        maxPft = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] < maxP)
                maxPft = max(maxPft, maxP - prices[i]);
            else
                maxP = prices[i];
            maxPftRight[i] = maxPft;
        }
        
        for (int i = 0; i < n; i++) {
            maxPft = max(maxPft, maxPftLeft[i] + maxPftRight[i]);
        }
        return maxPft;
    }
};
