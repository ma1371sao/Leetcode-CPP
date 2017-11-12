class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> maxLenValidStr;
		int removeLeft = 0;
		int removeRight = 0;
		unordered_set<string> validStr;
		for (auto c : s) {
			if (c == '(') removeLeft++;
			if (c == ')') {
				if (removeLeft > 0) removeLeft--;
				else removeRight++;
			}
		}
		dfs(removeLeft, removeRight, maxLenValidStr, s, 0, 0, "", validStr);
		return maxLenValidStr;
	}

	void dfs(int removeLeft, int removeRight, vector<string>& maxLenValidStr, string& s, int pos, int numPair, string curStr, unordered_set<string>& validStr) {
		if (pos == s.length()) {
			if (numPair == 0 && removeLeft == 0 && removeRight == 0 && validStr.find(curStr) == validStr.end()) {
				validStr.insert(curStr);
				maxLenValidStr.push_back(curStr);
			}
			return;
		}
		if (s[pos] == '(') {
			if (removeLeft > 0) dfs(removeLeft - 1, removeRight, maxLenValidStr, s, pos + 1, numPair, curStr, validStr);
			dfs(removeLeft, removeRight, maxLenValidStr, s, pos + 1, numPair + 1, curStr + s[pos], validStr);
		}
		else if (s[pos] == ')') {
			if (removeRight > 0) dfs(removeLeft, removeRight - 1, maxLenValidStr, s, pos + 1, numPair, curStr, validStr);
			if (numPair > 0) dfs(removeLeft, removeRight, maxLenValidStr, s, pos + 1, numPair - 1, curStr + s[pos], validStr);
		}
		else dfs(removeLeft, removeRight, maxLenValidStr, s, pos + 1, numPair, curStr + s[pos], validStr);
	}
};