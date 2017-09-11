class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int r = 0;
		int c = 0;
		vector<int> res;
		if (matrix.size() == 0) return res;
		int row = matrix.size();
		int col = matrix[0].size();
		int flag = 1;
		while (res.size() < row * col) {
			if (r < 0 && c >= col) {
				flag = 0;
				r = 1;
				c = col - 1;
			}
			if (c < 0 && r >= row) {
				flag = 1;
				r = row - 1;
				c = 1;
			}
			if (r < 0) {
				flag = 0;
				r = 0;
			}
			if (c >= col) {
				flag = 0;
				c = col - 1;
				r += 2;
			}
			if (c < 0) {
				flag = 1;
				c = 0;
			}
			if (r >= row) {
				flag = 1;
				r = row - 1;
				c += 2;
			}
			res.push_back(matrix[r][c]);
			if (flag) {
				r--;
				c++;
			}
			else {
				r++;
				c--;
			}
		}
		return res;
	}
};