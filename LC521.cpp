class Solution {
public:
	int findLUSlength(string a, string b) {
		int n = max(a.length(), b.length());
		if (a == b || n == 0) return -1;
		return n;
	}
};