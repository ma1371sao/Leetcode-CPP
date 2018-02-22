class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<int>> breakPts;
        for (int i = 0; i < s.length(); i++) {
            if (dictSet.find(s.substr(0, i + 1)) != dictSet.end())
                breakPts[i].push_back(0);
            for (int j = i - 1; j >= 0; j--) {
                if (breakPts.find(j) != breakPts.end() && dictSet.find(s.substr(j + 1, i - j)) != dictSet.end())
                    breakPts[i].push_back(j + 1);
            }
        }
        vector<string> res;
        if (breakPts.find(s.length() - 1) == breakPts.end()) return res;
        vector<string> words;
        dfs(res, s, breakPts, words, s.length() - 1);
        return res;
    }
    
    void dfs(vector<string>& res, string& s, unordered_map<int, vector<int>>& breakPts, vector<string>& words, int pos) {
        if (pos == -1) {
            string s;
            for (int i = words.size() - 1; i >= 0; i--)
                s += words[i] + " ";
            s.pop_back();
            res.push_back(s);
            return;
        }
        for (int start : breakPts[pos]) {
            words.push_back(s.substr(start, pos - start + 1));
            dfs(res, s, breakPts, words, start - 1);
            words.pop_back();
        }
    }
};
