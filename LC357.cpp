class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		if (n == 0)    return 1;
		dp[1] = 9;
		if (n == 1)    return 10;
		dp[2] = 9 * 9;
		if (n == 2)    return 91;
		int count = 8;
		int i;
		for (i = 3; i <= n && count>0; i++, count--)
			dp[i] = dp[i - 1] * count;
		int res = 0;
		for (int j = i - 1; j >= 0; j--)
			res += dp[j];
		return res;
	}
};