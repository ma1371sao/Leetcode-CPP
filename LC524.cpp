class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string longestWord = "";
		if (d.size() == 0) return "";
		int maxLen = 0;
		for (int i = 0; i < d.size(); i++) {
			if (d[i].length() >= maxLen && isSubseq(d[i], s)) {
				if (d[i].length() > maxLen) {
					longestWord = d[i];
					maxLen = d[i].length();
				}
				else {
					if (d[i] < longestWord) longestWord = d[i];
				}
			}
		}
		return longestWord;
	}
	bool isSubseq(string sub, string s) {
		int pos = 0;
		for (int i = 0; i < s.length() && pos < sub.length(); i++) {
			if (sub[pos] == s[i]) pos++;
		}
		if (pos >= sub.length()) return true;
		return false;
	}
};