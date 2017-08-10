class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		return getMoneyAmountBetweenLR(dp, 1, n);
	}

	int getMoneyAmountBetweenLR(vector<vector<int>>& dp, int left, int right) {
		if (left >= right || right <= left)
			return 0;
		if (dp[left][right])
			return dp[left][right];
		dp[left][right] = INT_MAX;
		for (int i = left; i <= right; i++) {
			int guaranteeMoneyWithI = i + max(getMoneyAmountBetweenLR(dp, left, i - 1), getMoneyAmountBetweenLR(dp, i + 1, right));
			dp[left][right] = min(dp[left][right], guaranteeMoneyWithI);
		}
		return dp[left][right];
	}
};