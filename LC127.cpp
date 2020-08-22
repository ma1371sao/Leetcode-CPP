class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (string word : wordList)
            wordSet.insert(word);
        if (!wordSet.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            string word = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for (int i = 0; i < word.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    if (word[i] == 'a' + j) continue;
                    string s = word;
                    s[i] = 'a' + j;
                    if (wordSet.count(s) && !visited.count(s)) {
                        q.push(make_pair(s, d + 1));
                        visited.insert(s);
                        
                        if (s == endWord) {
                            return d + 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
