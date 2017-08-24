class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int count = 0;
		int m = board.size();
		if (m == 0) return 0;
		int n = board[0].size();
		vector<vector<bool>> counted(m, vector<bool>(n, false));
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < n; c++) {
				if (board[r][c] == 'X' && !counted[r][c]) {
					count++;
					markBattleship(r, c, counted, board);
				}
			}
		}
		return count;
	}
	void markBattleship(int row, int col, vector<vector<bool>>& counted, vector<vector<char>>& board) {
		int m = board.size();
		int n = board[0].size();
		int r = row;
		int c = col;
		while (r < m && board[r][c] == 'X') {
			counted[r][c] = true;
			r++;
		}
		r = row;
		while (r >= 0 && board[r][c] == 'X') {
			counted[r][c] = true;
			r--;
		}
		r = row;
		while (c < n && board[r][c] == 'X') {
			counted[r][c] = true;
			c++;
		}
		c = col;
		while (c >= 0 && board[r][c] == 'X') {
			counted[r][c] = true;
			c--;
		}
	}
};