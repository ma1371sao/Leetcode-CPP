class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (!amount) return 0;
		if (!coins.size())   return -1;
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			int min = INT_MAX;
			for (int j = 0; j<coins.size(); j++) {
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
					int tmp = dp[i - coins[j]] + 1;
					if (tmp<min)
						min = tmp;
				}
			}
			if (min != INT_MAX)
				dp[i] = min;
		}
		return dp[amount];
	}
};