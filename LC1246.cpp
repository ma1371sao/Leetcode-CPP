int minimumMoves(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return n; 
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i - 1 >= 0) dp[i][i - 1] = 0;
    }
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
            if (nums[i] == nums[i + 1])
                dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            for (int k = i + 2; k <= j; k++) {
                if (nums[i] == nums[k])
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}
