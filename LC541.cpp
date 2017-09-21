class Solution {
public:
	string reverseStr(string s, int k) {
		if (k == 0 || s.length() == 0) return s;
		int pos = 0;
		while (pos < s.length()) {
			if (s.length() - pos < k)
				reverseSubStr(s, pos, s.length());
			else {
				reverseSubStr(s, pos, pos + k);
			}
			pos += 2 * k;
		}
		return s;
	}
	void reverseSubStr(string& s, int start, int end) {
		int i, j;
		for (i = start, j = end - 1; i < j; i++, j--) {
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
};