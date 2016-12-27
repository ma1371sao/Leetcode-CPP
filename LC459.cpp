class Solution {
public:
	bool repeatedSubstringPattern(string str) {
		int n = str.length();
		string res;
		for (int i = 0; i<n / 2; i++) {
			res.push_back(str[i]);
			if (n%res.length() == 0) {
				int k = n / res.length();
				string s;
				for (int i = 0; i<k; i++)
					s = s + res;
				if (s == str)  return true;
			}
		}
		return false;
	}
};