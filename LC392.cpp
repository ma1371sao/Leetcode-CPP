class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.size() == 0)
			return true;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == s[0] && isSubsequence(s.substr(1), t.substr(i + 1))) {
				return true;
			}
		}
		return false;
	}
};