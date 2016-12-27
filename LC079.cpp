class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int n = word.length();
		if (n == 0)
			return true;
		int row = board.size();
		if (row == 0)
			return false;
		int col = board[0].size();
		int vis[1000][1000];
		for (int i = 0; i<row; i++)
			memset(vis[i], 0, sizeof(vis[i]));
		for (int r = 0; r<row; r++)
			for (int c = 0; c<col; c++)
				if (board[r][c] == word[0])
				{
					vis[r][c] = 1;
					if (DFS(board, word, 1, row, col, r, c, vis))
						return true;
					else
						vis[r][c] = 0;
				}
		return false;
	}
	bool DFS(vector<vector<char>>& board, string word, int pos, int row, int col, int r, int c, int vis[][1000])
	{
		if (pos == word.length())
			return true;
		if (r - 1 >= 0 && board[r - 1][c] == word[pos] && vis[r - 1][c] == 0)
		{
			vis[r - 1][c] = 1;
			if (DFS(board, word, pos + 1, row, col, r - 1, c, vis))
				return true;
			else
				vis[r - 1][c] = 0;
		}
		if (r + 1<row && board[r + 1][c] == word[pos] && vis[r + 1][c] == 0)
		{
			vis[r + 1][c] = 1;
			if (DFS(board, word, pos + 1, row, col, r + 1, c, vis))
				return true;
			else
				vis[r + 1][c] = 0;
		}
		if (c - 1 >= 0 && board[r][c - 1] == word[pos] && vis[r][c - 1] == 0)
		{
			vis[r][c - 1] = 1;
			if (DFS(board, word, pos + 1, row, col, r, c - 1, vis))
				return true;
			else
				vis[r][c - 1] = 0;
		}
		if (c + 1<col && board[r][c + 1] == word[pos] && vis[r][c + 1] == 0)
		{
			vis[r][c + 1] = 1;
			if (DFS(board, word, pos + 1, row, col, r, c + 1, vis))
				return true;
			else
				vis[r][c + 1] = 0;
		}
		return false;
	}
};