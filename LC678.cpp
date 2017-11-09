class Solution {
public:
	bool checkValidString(string s) {
		int lower = 0;
		int upper = 0;
		for (char c : s) {
			if (c == '(') {
				lower++;
				upper++;
			}
			else if (c == ')') {
				lower--;
				upper--;
			}
			else {
				lower--;
				upper++;
			}
			lower = max(lower, 0);
			if (upper < 0) return false;
		}
		return lower == 0;
	}
};