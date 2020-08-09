class Solution {
public:
    int minCut(string s) {
        if (s.length() == 0) return 0;
        
        int n = s.length();
        vector<int> dpMinPart(n);
        vector<vector<bool>> dpIsPalm(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dpMinPart[i] = i;
            
            for (int j = i; j >= 0; j--) {
                if (j == i) dpIsPalm[j][i] = true;
                else if (j + 1 == i && s[j] == s[i]) dpIsPalm[j][i] = true;
                else if (s[j] == s[i]) dpIsPalm[j][i] = dpIsPalm[j + 1][i - 1];
                
                if (dpIsPalm[j][i]) {
                    if (j == 0) dpMinPart[i] = 0;
                    else dpMinPart[i] = min(dpMinPart[i], dpMinPart[j - 1] + 1);
                }
            }
        }
        return dpMinPart[n - 1];
    }
};
