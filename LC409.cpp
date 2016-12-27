class Solution {
public:
	int longestPalindrome(string s) {
		if (s.length() == 0)   return 0;
		int res = 0;
		unordered_map<char, int> hash;
		for (int i = 0; i<s.length(); i++)
			hash[s[i]]++;
		int odd = 0;
		for (unordered_map<char, int>::iterator it = hash.begin(); it != hash.end(); it++) {
			res = res + it->second / 2 * 2;
			if (it->second % 2)
				odd = 1;
		}
		return res + odd;
	}
};