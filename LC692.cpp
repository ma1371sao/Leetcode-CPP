struct cmp {
	bool operator() (const pair<string, int>& a, const pair<string, int>& b) {
		if (a.second != b.second) {
			return a.second > b.second;
		}
		return a.first < b.first;
	}
};
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> kFreWords(k);
		if (k == 0 || words.size() == 0) return kFreWords;
		priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> freWords;
		unordered_map<string, int> word_fre;
		for (int i = 0; i < words.size(); i++) {
			word_fre[words[i]]++;
		}
		for (auto& it : word_fre) {
			if (freWords.size() < k) freWords.push(make_pair(it.first, it.second));
			else if (freWords.top().second < it.second || (freWords.top().second == it.second && it.first < freWords.top().first)) {
				freWords.pop();
				freWords.push(make_pair(it.first, it.second));
			}
		}
		for (int i = k - 1; i >= 0; i--) {
			kFreWords[i] = freWords.top().first;
			freWords.pop();
		}
		return kFreWords;
	}
};