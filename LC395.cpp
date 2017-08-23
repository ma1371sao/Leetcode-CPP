class Solution {
public:
	int longestSubstring(string s, int k) {
		int substringLen = 0;
		bool hasBreakPoint = false;
		unordered_map<char, int> characterNum;
		int start = 0;
		int n = s.length();
		for (int i = 0; i < s.length(); i++) {
			characterNum[s[i]]++;
		}
		for (int i = 0; i < s.length(); i++) {
			if (characterNum[s[i]] < k) {
				hasBreakPoint = true;
				substringLen = max(substringLen, longestSubstring(s.substr(start, i - start), k));
				start = i + 1;
			}
		}
		if (!hasBreakPoint) return s.length();
		if (start < n) {
			substringLen = max(substringLen, longestSubstring(s.substr(start, n - start), k));
		}
		return substringLen;
	}
};