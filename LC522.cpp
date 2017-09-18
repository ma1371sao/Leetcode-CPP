class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		if (strs.size() == 0) return -1;
		int maxLen = -1;
		for (int i = 0; i < strs.size(); i++) {
			bool isSub = false;
			for (int j = 0; j < strs.size(); j++) {
				if (i != j && isSubsequence(strs[j], strs[i])) {
					isSub = true;
					break;
				}
			}
			if (!isSub) maxLen = max(maxLen, (int)strs[i].length());
		}
		return maxLen;
	}

	bool isSubsequence(string& s1, string& s2) {
		if (s1.length() < s2.length() || (s1.length() == s2.length() && s1 != s2)) return false;
		if (s1 == s2) return true;
		int pos2 = 0;
		for (int pos1 = 0; pos1 < s1.length() && pos2 < s2.length(); pos1++) {
			if (s1[pos1] == s2[pos2]) {
				pos2++;
			}
		}
		if (pos2 >= s2.length()) return true;
		return false;
	}
};