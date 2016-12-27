class Solution {
public:
	void reverseWords(string &s) {
		string noblank;
		for (int i = 0; i<s.length(); i++) {
			if (noblank.length() == 0 && s[i] == ' ')
				continue;
			if (s[i] != ' ')
				noblank.push_back(s[i]);
			else if (noblank.back() != ' ')
				noblank.push_back(s[i]);
		}
		if (noblank.back() == ' ')
			s = noblank.substr(0, noblank.length() - 1);
		else
			s = noblank;
		int n = s.length();
		reversestring(s, 0, n - 1);
		int blank = s.find(' ');
		int start = 0;
		while (blank != string::npos) {
			reversestring(s, start, blank - 1);
			start = blank + 1;
			blank = s.find(' ', start);
		}
		reversestring(s, start, n - 1);
	}
	void reversestring(string &s, int start, int end) {
		int i, j;
		for (i = start, j = end; i<j; i++, j--) {
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
};