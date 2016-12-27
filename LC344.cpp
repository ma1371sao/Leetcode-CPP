class Solution {
public:
	string reverseString(string s) {
		int l = s.length();
		string ans;
		for (int i = l - 1; i >= 0; i--)
			ans.push_back(s[i]);
		return ans;
	}
};