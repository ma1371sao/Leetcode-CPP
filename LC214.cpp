class Solution {
public:
	string shortestPalindrome(string s) {
		if (s == "") return s;
		int mid;
		bool isOdd;
		string shortestPal = s;
		for (int r = s.length() - 1; r >= 0; r--) {
			mid = r / 2;
			if ((r + 1) % 2 == 1) {
				isOdd = true;
				bool isPal = true;
				for (int i = mid; i >= 0; i--) {
					if (s[mid - i] != s[mid + i]) {
						isPal = false;
						break;
					}
				}
				if (isPal) break;
			}
			else if (s[mid] == s[mid + 1]) {
				isOdd = false;
				bool isPal = true;
				for (int i = mid; i >= 0; i--) {
					if (s[mid - i] != s[mid + 1 + i]) {
						isPal = false;
						break;
					}
				}
				if (isPal) break;
			}
		}
		if (isOdd) {
			string add = s.substr(mid * 2 + 1);
			reverse(add.begin(), add.end());
			shortestPal = add + shortestPal;
		}
		else {
			string add = s.substr(mid * 2 + 2);
			reverse(add.begin(), add.end());
			shortestPal = add + shortestPal;
		}
		return shortestPal;
	}
};