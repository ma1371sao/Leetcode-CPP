class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictSet;
        for (string word : wordDict)
            dictSet.insert(word);
        
        int n = s.length();
        vector<bool> dp(n, false);
        for (int i = 0; i < n; i++) {
            if (dictSet.count(s.substr(0, i + 1)))
                dp[i] = true;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    if (dictSet.count(s.substr(j + 1, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
