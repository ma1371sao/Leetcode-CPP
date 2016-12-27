class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.erase(wordList.find(beginWord));
		if (wordList.find(endWord) == wordList.end())  wordList.insert(endWord);
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		while (!q.empty()) {
			pair<string, int> p = q.front();
			q.pop();
			if (p.first == endWord)  return p.second;
			for (int i = 0; i<p.first.length(); i++) {
				string tmp = p.first;
				for (int j = 0; j<26; j++) {
					tmp[i] = 'a' + j;
					if (wordList.find(tmp) != wordList.end()) {
						q.push(make_pair(tmp, p.second + 1));
						wordList.erase(tmp);
					}
				}
			}
		}
		return 0;
	}
};