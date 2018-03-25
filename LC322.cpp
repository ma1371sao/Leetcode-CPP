class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MIN);
        vector<int> num(amount + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int v = coins[i]; v <= amount; v++)
                if (dp[v] <= dp[v - coins[i]] + coins[i]) {
                    if (dp[v] == dp[v - coins[i]] + coins[i] && num[v] < num[v - coins[i]] + 1)
                        continue;
                    dp[v] = dp[v - coins[i]] + coins[i];
                    num[v] = num[v - coins[i]] + 1;
                }
        }
        return (dp[amount] < 0 ? -1 : num[amount]);
    }
};