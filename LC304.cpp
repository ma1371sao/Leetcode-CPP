class NumMatrix {
public:
	vector<vector<int>> m;
	vector<vector<int>> sum;
	NumMatrix(vector<vector<int>> &matrix) {
		m = matrix;
		int row = m.size();
		if (row != 0) {
			int col = m[0].size();
			vector<vector<int>> v(row + 1, vector<int>(col + 1, 0));
			sum = v;
			int val = 0;
			for (int r = 0; r<row; r++)
				for (int c = 0; c<col; c++) {
					val += m[r][c];
					sum[r + 1][c + 1] = val;
				}
			for (int r = 2; r<row + 1; r++)
				sum[r][0] = sum[r - 1][col];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int res = 0;
		for (int r = row1; r <= row2; r++)
			res += sum[r + 1][col2 + 1] - sum[r + 1][col1];
		return res;
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);