class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());
        vector<vector<bool>> canSegment(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); i++) {
            if (dictSet.find(s.substr(0, i + 1)) != dictSet.end())
                canSegment[0][i] = true;
        }
        for (int i = 1; i < s.length(); i++) {
            if (!canSegment[0][i]) {
                for (int j = i - 1; j >= 0; j--) {
                    if (canSegment[0][j] && dictSet.find(s.substr(j + 1, i - j)) != dictSet.end()) {
                        canSegment[0][i] = true;
                        break;
                    }
                }
            }
        }
        return canSegment[0][s.length() - 1];
    }
};
