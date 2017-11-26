class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n == 0) return res;
		dfs(res, "", n, n, 0);
		return res;
	}

	void dfs(vector<string>& res, string cur, int left, int right, int pairNum) {
		if (left == 0 && right == 0 && pairNum == 0) {
			res.push_back(cur);
			return;
		}
		if (left > 0) dfs(res, cur + "(", left - 1, right, pairNum + 1);
		if (right > 0 && pairNum > 0) dfs(res, cur + ")", left, right - 1, pairNum - 1);
	}
};