class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.size() == 0) return 0;
		vector<vector<int>> maxNum(m + 1, vector<int>(n + 1, 0));
		vector<int> numM(strs.size(), 0);
		vector<int> numN(strs.size(), 0);
		for (int i = 0; i < strs.size(); i++) {
			for (int j = 0; j < strs[i].size(); j++) {
				if (strs[i][j] == '0') numM[i]++;
				if (strs[i][j] == '1') numN[i]++;
			}
		}
		for (int i = 0; i < strs.size(); i++) {
			for (int p = m; p >= numM[i]; p--) {
				for (int q = n; q >= numN[i]; q--) {
					maxNum[p][q] = max(1 + maxNum[p - numM[i]][q - numN[i]], maxNum[p][q]);
				}
			}
		}
		return maxNum[m][n];
	}
};