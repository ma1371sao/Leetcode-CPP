class Solution {
public:
	string minWindow(string s, string t) {
		if (s.length() == 0 || t.length() == 0) return "";
		unordered_map<char, int> charNum;
		for (char c : t)
			charNum[c]++;
		queue<int> pos;
		int length = 0;
		int minLen = INT_MAX;
		string res = "";
		for (int i = 0; i < s.length(); i++) {
			if (t.find(s[i]) != string::npos) {
				charNum[s[i]]--;
				if (charNum[s[i]] >= 0)
					length++;
				pos.push(i);
			}
			while (length == t.length()) {
				if (minLen > i - pos.front() + 1) {
					minLen = i - pos.front() + 1;
					res = s.substr(pos.front(), minLen);
				}
				charNum[s[pos.front()]]++;
				if (charNum[s[pos.front()]] > 0)
					length--;
				pos.pop();
			}
		}
		return res;
	}
};