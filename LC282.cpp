class Solution {
public:
	vector<string> ans;
	vector<string> addOperators(string num, int target) {
		int n = num.size();
		if (n == 0 || n == 1)
			return ans;
		DFS(num, 0, 0, -target, "", 1);
		return ans;
	}
	void DFS(string& num, int pos, long pre, long sum, string s, int val)
	{
		pre = pre * 10 + num[pos] - '0';
		if (pre>INT_MAX) return;
		if (sum + pre*val == 0 && pos == num.length() - 1)
			ans.push_back(s + num[pos]);
		if (pos == num.length() - 1)
			return;
		if (pre) DFS(num, pos + 1, pre, sum, s + num[pos], val);
		DFS(num, pos + 1, 0, sum + pre*val, s + num[pos] + '+', 1);
		DFS(num, pos + 1, 0, sum + pre*val, s + num[pos] + '-', -1);
		DFS(num, pos + 1, 0, sum, s + num[pos] + '*', val*pre);
	}
};