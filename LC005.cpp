class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        string ans = s.substr(0, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) dp[i][j] = true;
                else if (s[i] == s[j]) {
                    if (j == i + 1) dp[i][j] = true;
                    else if (dp[i + 1][j - 1]) dp[i][j] = true;
                }
                
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    ans = s.substr(i, maxLen);
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;
        string ans;
        ans.push_back(s[0]);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            int l = i - 1;
            int r = i + 1;
            for (; l >= 0 && r < n && s[l] == s[r]; l--, r++);
            l++;
            r--;
            int len = r - l + 1;
            if (maxLen < len) {
                maxLen = len;
                ans = s.substr(l, maxLen);
            }
            
            if (i + 1 < n && s[i] == s[i + 1]) {
                int l = i - 1;
                int r = i + 2;
                for (; l >= 0 && r < n && s[l] == s[r]; l--, r++);
                l++;
                r--;
                int len = r - l + 1;
                if (maxLen < len) {
                    maxLen = len;
                    ans = s.substr(l, maxLen);
                }
            }
        }
        return ans;
    }
};
