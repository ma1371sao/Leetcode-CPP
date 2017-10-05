class Solution {
public:
	string reverseWords(string s) {
		string res;
		int space = s.find(' ');
		int start = 0;
		while (space != string::npos) {
			if (start > 0) res += " ";
			string sub = s.substr(start, space - start);
			reverse(sub.begin(), sub.end());
			res += sub;
			start = space + 1;
			space = s.find(' ', start);
		}

		string sub = s.substr(start);
		reverse(sub.begin(), sub.end());
		if (start > 0) res += " ";
		res += sub;
		return res;
	}
};