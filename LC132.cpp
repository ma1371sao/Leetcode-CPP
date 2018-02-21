class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isPal(s.length(), vector<bool>(s.length(), false));
        vector<int> minCut(s.length() + 1, 0);
        isPal[0][0] = true;
        for (int i = 1; i < s.length(); i++) {
            isPal[i][i] = true;
            minCut[i + 1] = minCut[i] + 1;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == s[i] && (i < j + 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    if (j == 0)
                        minCut[i + 1] = 0;
                    else
                        minCut[i + 1] = min(minCut[i + 1], minCut[j] + 1);
                }
            }
        }
        return minCut[s.length()];
    }
};
