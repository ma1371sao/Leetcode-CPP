#include<cstring>
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		backtrack(board, 0, 0);
	}
	bool backtrack(vector<vector<char>>& board, int r, int c)
	{
		if (r == 8 && c == 9)
			return true;
		if (c == 9)
		{
			r++;
			c = 0;
		}
		if (board[r][c] != '.')
		{
			if (backtrack(board, r, c + 1))
				return true;
		}
		else
		{
			int arr[10];
			memset(arr, 0, sizeof(arr));
			for (int i = 0; i<9; i++)
			{
				if (board[r][i] != '.')
					arr[board[r][i] - '0'] = 1;
				if (board[i][c] != '.')
					arr[board[i][c] - '0'] = 1;
			}
			int p = (r / 3) * 3;
			int q = (c / 3) * 3;
			for (int i = p; i<p + 3; i++)
				for (int j = q; j<q + 3; j++)
					if (board[i][j] != '.')
						arr[board[i][j] - '0'] = 1;
			for (int i = 1; i<10; i++)
				if (arr[i] == 0)
				{
					board[r][c] = i + '0';
					if (backtrack(board, r, c + 1))
						return true;
					board[r][c] = '.';
				}
		}
		return false;
	}
};