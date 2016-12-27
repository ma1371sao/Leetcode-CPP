/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

using namespace std;
class solution {
	int worddistance(vector<string> wordlist, string word1, string word2) {
		unordered_map<string, vector<int>> wordpos;
		for (int i = 0; i < wordlist.size(); i++) {
			if (wordlist[i] == word1)	wordpos[word1].push_back(i);
			if (wordlist[i] == word2)	wordpos[word2].push_back(i);
		}
		int i = 0;
		int j = 0;
		int min = INT_MAX;
		while (i < wordpos[word1].size() && j < wordpos[word2].size()) {
			int tmp = abs(wordpos[word1][i] - wordpos[word2][j]);
			if (min > tmp)	min = tmp;
			if (wordpos[word1][i] < wordpos[word2][j])	i++;
			else j++;
		}
	}
};