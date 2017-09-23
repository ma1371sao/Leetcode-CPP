class Solution {
public:
	bool checkRecord(string s) {
		int numA = 0;
		int continuL = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') {
				numA++;
				continuL = 0;
				if (numA > 1) return false;
			}
			else if (s[i] == 'L') {
				continuL++;
				if (continuL > 2) return false;
			}
			else {
				continuL = 0;
			}
		}
		return true;
	}
};