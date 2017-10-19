class Solution {
public:
	void reverseWords(string &s) {
		int pos = 0;
		bool empty = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				empty = true;
				s[pos++] = s[i];
			}
			else if (empty) {
				s[pos++] = s[i];
				empty = false;
			}
		}
		if (pos == 0) {
			s = "";
			return;
		}
		if (s[pos - 1] == ' ') pos--;
		s = s.substr(0, pos);
		reverse(s.begin(), s.end());
		int start = 0;
		while (1) {
			int pos = s.find(' ', start);
			if (pos == string::npos) {
				reverse(s.begin() + start, s.end());
				break;
			}
			else {
				reverse(s.begin() + start, s.begin() + pos);
				start = pos + 1;
			}
		}
	}
};