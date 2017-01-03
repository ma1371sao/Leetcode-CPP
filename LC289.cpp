class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int row = board.size();
		if (row == 0)  return;
		int col = board[0].size();
		if (col == 0)  return;
		for (int r = 0; r<row; r++)
			for (int c = 0; c<col; c++) {
				int count = Count(r, c, board);
				if (count == 3 || (count == 2 && board[r][c] % 10))
					board[r][c] += 10;
			}
		for (int r = 0; r<row; r++)
			for (int c = 0; c<col; c++)
				if (board[r][c] >= 10)
					board[r][c] = 1;
				else
					board[r][c] = 0;
	}
	int Count(int r, int c, vector<vector<int>>& board) {
		int res = 0;
		if (r>0 && board[r - 1][c] % 10) res++;
		if (r<board.size() - 1 && board[r + 1][c] % 10) res++;
		if (c>0 && board[r][c - 1] % 10) res++;
		if (c<board[0].size() - 1 && board[r][c + 1] % 10) res++;
		if (r>0 && c>0 && board[r - 1][c - 1] % 10) res++;
		if (r>0 && c<board[0].size() - 1 && board[r - 1][c + 1] % 10) res++;
		if (r<board.size() - 1 && c>0 && board[r + 1][c - 1] % 10) res++;
		if (r<board.size() - 1 && c<board[0].size() - 1 && board[r + 1][c + 1] % 10) res++;
		return res;
	}
};