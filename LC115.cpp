class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.length() < t.length()) return 0;
        int ls = s.length();
        int lt = t.length();
        vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, 0));
        for (int i = 0; i <= ls; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= ls; i++) {
            for (int j = 1; j <=lt && j <= i; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[ls][lt];
    }
};
