class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> disZero(row, vector<int>(col, 0));
		queue<pair<int, int>> q;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] != 0) {
					disZero[i][j] = INT_MAX;
				}
				else {
					q.push(make_pair(i, j));
				}
			}
		}
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (r > 0 && disZero[r - 1][c] > disZero[r][c]) {
				disZero[r - 1][c] = disZero[r][c] + 1;
				q.push(make_pair(r - 1, c));
			}
			if (r < row - 1 && disZero[r + 1][c] > disZero[r][c]) {
				disZero[r + 1][c] = disZero[r][c] + 1;
				q.push(make_pair(r + 1, c));
			}
			if (c > 0 && disZero[r][c - 1] > disZero[r][c]) {
				disZero[r][c - 1] = disZero[r][c] + 1;
				q.push(make_pair(r, c - 1));
			}
			if (c < col - 1 && disZero[r][c + 1] > disZero[r][c]) {
				disZero[r][c + 1] = disZero[r][c] + 1;
				q.push(make_pair(r, c + 1));
			}
		}
		return disZero;
	}
};