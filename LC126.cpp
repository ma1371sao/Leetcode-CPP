class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return res;
        if (beginWord == endWord) {
            vector<string> path(1, beginWord);
            res.push_back(path);
            return res;
        }
        if (wordSet.find(beginWord) != wordSet.end()) wordSet.erase(beginWord);
        unordered_map<string, vector<pair<string, int>>> parents;
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 0));
        int minLen = INT_MAX;
        while (!q.empty()) {
            string s = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (minLen < depth) break;
            if (s == endWord) minLen = depth;
            for (int i = 0; i < s.length(); i++) {
                string tmp = s;
                for (int j = 0; j < 26; j++) {
                    tmp[i] = 'a' + j;
                    if (wordSet.find(tmp) != wordSet.end()) {
                        q.push(make_pair(tmp, depth + 1));
                        wordSet.erase(tmp);
                        parents[tmp].push_back(make_pair(s, depth));
                    }
                    else if (parents.find(tmp) != parents.end() && parents[tmp][0].second == depth)
                        parents[tmp].push_back(make_pair(s, depth));
                }
            }
        }
        if (minLen == INT_MAX) return res;
        vector<string> path(minLen + 1);
        dfs(endWord, beginWord, minLen, parents, res, path);
        return res;
    }
    
    void dfs(string curWord, string& beginWord, int restLen, unordered_map<string, vector<pair<string, int>>>& parents,
             vector<vector<string>>& res, vector<string>& path) {
        path[restLen] = curWord;
        if (restLen == 0) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < parents[curWord].size() && parents[curWord][i].second < restLen; i++) {
            dfs(parents[curWord][i].first, beginWord, restLen - 1, parents, res, path);
        }
    }
};
