class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int row = board.size();
		if (row == 0)  return;
		int col = board[0].size();
		if (col == 0)  return;
		vector<vector<int>> uni(row, vector<int>(col, 0));
		for (int c = 0; c<col; c++) {
			if (board[0][c] == 'O' && !uni[0][c]) {
				queue<pair<int, int>> q;
				uni[0][c] = 1;
				q.push(make_pair(0, c));
				while (!q.empty()) {
					int i = q.front().first;
					int j = q.front().second;
					q.pop();
					if (i - 1 >= 0 && !uni[i - 1][j] && board[i - 1][j] == 'O') {
						q.push(make_pair(i - 1, j));
						uni[i - 1][j] = 1;
					}
					if (i + 1<row && !uni[i + 1][j] && board[i + 1][j] == 'O') {
						q.push(make_pair(i + 1, j));
						uni[i + 1][j] = 1;
					}
					if (j - 1 >= 0 && !uni[i][j - 1] && board[i][j - 1] == 'O') {
						q.push(make_pair(i, j - 1));
						uni[i][j - 1] = 1;
					}
					if (j + 1<col && !uni[i][j + 1] && board[i][j + 1] == 'O') {
						q.push(make_pair(i, j + 1));
						uni[i][j + 1] = 1;
					}
				}
			}
		}
		for (int c = 0; c<col; c++) {
			if (board[row - 1][c] == 'O' && !uni[row - 1][c]) {
				queue<pair<int, int>> q;
				uni[row - 1][c] = 1;
				q.push(make_pair(row - 1, c));
				while (!q.empty()) {
					int i = q.front().first;
					int j = q.front().second;
					q.pop();
					if (i - 1 >= 0 && !uni[i - 1][j] && board[i - 1][j] == 'O') {
						q.push(make_pair(i - 1, j));
						uni[i - 1][j] = 1;
					}
					if (i + 1<row && !uni[i + 1][j] && board[i + 1][j] == 'O') {
						q.push(make_pair(i + 1, j));
						uni[i + 1][j] = 1;
					}
					if (j - 1 >= 0 && !uni[i][j - 1] && board[i][j - 1] == 'O') {
						q.push(make_pair(i, j - 1));
						uni[i][j - 1] = 1;
					}
					if (j + 1<col && !uni[i][j + 1] && board[i][j + 1] == 'O') {
						q.push(make_pair(i, j + 1));
						uni[i][j + 1] = 1;
					}
				}
			}
		}
		for (int r = 0; r<row; r++) {
			if (board[r][0] == 'O' && !uni[r][0]) {
				queue<pair<int, int>> q;
				uni[r][0] = 1;
				q.push(make_pair(r, 0));
				while (!q.empty()) {
					int i = q.front().first;
					int j = q.front().second;
					q.pop();
					if (i - 1 >= 0 && !uni[i - 1][j] && board[i - 1][j] == 'O') {
						q.push(make_pair(i - 1, j));
						uni[i - 1][j] = 1;
					}
					if (i + 1<row && !uni[i + 1][j] && board[i + 1][j] == 'O') {
						q.push(make_pair(i + 1, j));
						uni[i + 1][j] = 1;
					}
					if (j - 1 >= 0 && !uni[i][j - 1] && board[i][j - 1] == 'O') {
						q.push(make_pair(i, j - 1));
						uni[i][j - 1] = 1;
					}
					if (j + 1<col && !uni[i][j + 1] && board[i][j + 1] == 'O') {
						q.push(make_pair(i, j + 1));
						uni[i][j + 1] = 1;
					}
				}
			}
		}
		for (int r = 0; r<row; r++) {
			if (board[r][col - 1] == 'O' && !uni[r][col - 1]) {
				queue<pair<int, int>> q;
				uni[r][col - 1] = 1;
				q.push(make_pair(r, col - 1));
				while (!q.empty()) {
					int i = q.front().first;
					int j = q.front().second;
					q.pop();
					if (i - 1 >= 0 && !uni[i - 1][j] && board[i - 1][j] == 'O') {
						q.push(make_pair(i - 1, j));
						uni[i - 1][j] = 1;
					}
					if (i + 1<row && !uni[i + 1][j] && board[i + 1][j] == 'O') {
						q.push(make_pair(i + 1, j));
						uni[i + 1][j] = 1;
					}
					if (j - 1 >= 0 && !uni[i][j - 1] && board[i][j - 1] == 'O') {
						q.push(make_pair(i, j - 1));
						uni[i][j - 1] = 1;
					}
					if (j + 1<col && !uni[i][j + 1] && board[i][j + 1] == 'O') {
						q.push(make_pair(i, j + 1));
						uni[i][j + 1] = 1;
					}
				}
			}
		}
		for (int r = 0; r<row; r++)
			for (int c = 0; c<col; c++)
				if (board[r][c] == 'O' && !uni[r][c])
					board[r][c] = 'X';
	}
};