class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        wordList.push_back(beginWord);
        int n = wordList.size();
        int beginIdx = n - 1;
        int endIdx = -1;
        unordered_map<int, vector<int>> adj;
        unordered_map<string, int> wordIdx;
        
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                endIdx = i;
            }
            wordIdx[wordList[i]] = i;
        }
        if (endIdx == -1) return ans;
        
        for (int i = 0; i < n; i++) {
            int len = wordList[0].length();
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < 26; k++) {
                    string s = wordList[i];
                    s[j] = 'a' + k;
                    if (wordIdx.count(s)) {
                        adj[i].push_back(wordIdx[s]);
                    }
                }
            }
        }
        
        queue<int> q;
        q.push(beginIdx);
        int minDeep = INT_MAX;
        vector<int> dist(n, -1);
        dist[beginIdx] = 0;
        while (!q.empty()) {
            int idx = q.front();
            int deep = dist[idx];
            if (idx == endIdx) minDeep = deep;
            if (deep > minDeep) break;
            q.pop();
            for (int i : adj[idx]) {
                if (dist[i] == -1) {
                    q.push(i);
                    dist[i] = deep + 1;
                }
            }
        }
        
        vector<string> curPath;
        curPath.push_back(wordList[beginIdx]);
        dfs(beginIdx, wordList, adj, ans, dist, curPath, endIdx);
        return ans;
    }
    
    void dfs(int idx, vector<string>& wordList, unordered_map<int, vector<int>>& adj, vector<vector<string>>& ans, 
             vector<int>& dist, vector<string>& curPath, int endIdx) {
        
        if (idx == endIdx) {
            ans.push_back(curPath);
            return;
        }
        
        for (int i : adj[idx]) {
            if (dist[i] == dist[idx] + 1) {
                curPath.push_back(wordList[i]);
                dfs(i, wordList, adj, ans, dist, curPath, endIdx);
                curPath.pop_back();
            }
        }
    }
};
