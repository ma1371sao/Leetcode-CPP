class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n == 0) return;
		int i, j;
		for (i = 0, j = n - 1; i < j; i++, j--) {
			for (int c = 0; c < n; c++) {
				int tmp = matrix[i][c];
				matrix[i][c] = matrix[j][c];
				matrix[j][c] = tmp;
			}
		}
		for (int r = 0; r < n; r++) {
			for (int c = r + 1; c < n; c++) {
				int tmp = matrix[r][c];
				matrix[r][c] = matrix[c][r];
				matrix[c][r] = tmp;
			}
		}
	}
};