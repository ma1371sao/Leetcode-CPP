class Solution {
public:
	string decodeString(string s) {
		int num = 0;
		int start = -1;
		int firstParenthese = -1;
		int repeat = 0;
		string decodedString;
		int flag = 0;
		if (s.find('[') == string::npos)
			return s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z' && firstParenthese == -1) {
				decodedString += s[i];
			}
			if (s[i] >= '0' && s[i] <= '9' && start == -1) {
				start = i;
			}
			if (s[i] == '[') {
				num++;
				if (num == 1) {
					repeat = stoi(s.substr(start, i - start));
					firstParenthese = i;
				}
			}
			if (s[i] == ']') {
				num--;
				if (num == 0) {
					string nxtString = decodeString(s.substr(firstParenthese + 1, i - firstParenthese - 1));
					for (int i = 0; i < repeat; i++) {
						decodedString += nxtString;
					}
					start = -1;
					firstParenthese = -1;
				}
			}
		}
		return decodedString;
	}
};