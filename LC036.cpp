class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int lr = board.size();
		if (!lr)
			return true;
		int count[10];
		memset(count, 0, sizeof(count));
		int lc = board[0].size();
		map<char, int> m;
		for (char c = '1'; c <= '9'; c++)
			m[c] = c - 48;
		m['.'] = 0;
		for (int i = 0; i<lr; i++)
		{
			memset(count, 0, sizeof(count));
			for (int j = 0; j<lc; j++)
			{
				count[m[board[i][j]]]++;
				count[0] = 0;
				if (count[m[board[i][j]]]>1)
					return false;
			}
		}
		for (int j = 0; j<lc; j++)
		{
			memset(count, 0, sizeof(count));
			for (int i = 0; i<lr; i++)
			{
				count[m[board[i][j]]]++;
				count[0] = 0;
				if (count[m[board[i][j]]]>1)
					return false;
			}
		}
		for (int i = 0; i<lr - 2; i = i + 3)
			for (int j = 0; j<lc - 2; j = j + 3)
			{
				memset(count, 0, sizeof(count));
				for (int r = i; r<i + 3; r++)
					for (int c = j; c<j + 3; c++)
					{
						count[m[board[r][c]]]++;
						count[0] = 0;
						if (count[m[board[r][c]]]>1)
							return false;
					}
			}
		return true;
	}
};