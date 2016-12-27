class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		if (s.length() == 0)   return res;
		vector<string> v;
		dfs(s, res, v);
		return res;
	}
	void dfs(string s, vector<vector<string>>& res, vector<string>& v) {
		if (s.length() == 0) {
			res.push_back(v);
			return;
		}
		for (int i = 0; i<s.length(); i++) {
			if (isPal(s.substr(0, i + 1))) {
				v.push_back(s.substr(0, i + 1));
				dfs(s.substr(i + 1), res, v);
				v.pop_back();
			}
		}
	}
	bool isPal(string s) {
		int n = s.length();
		if (n == 1)    return true;
		int i, j;
		for (i = 0, j = n - 1; i <= j; i++, j--)
			if (s[i] != s[j])
				return false;
		return true;
	}
};