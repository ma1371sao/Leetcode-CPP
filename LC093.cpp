class Solution {
public:
	vector<string> ans;
	vector<string> restoreIpAddresses(string s) {
		int n = s.length();
		if (n<4 || n>12) return ans;
		DFS(0, "", s, 0);
		return ans;
	}
	void DFS(int pos, string sub, string s, int k) {
		if (pos == s.length() && k == 4) {
			sub.pop_back();
			ans.push_back(sub);
			return;
		}
		else if (pos == s.length()) return;
		for (int num = 1; num <= 3; num++) {
			if (pos + num <= s.length())
				if (num == 1 || (num>1 && s[pos] != '0')) {
					int tmp = 0;
					int t = 0;
					for (int j = pos + num - 1; j >= pos; j--)
						tmp = tmp + (s[j] - '0')*pow(10, t++);
					if (tmp <= 255)
						DFS(pos + num, sub + s.substr(pos, num) + ".", s, k + 1);
				}
		}
	}
};