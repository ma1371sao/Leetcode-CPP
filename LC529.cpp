class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		queue<pair<int, int>> q;
		q.push(make_pair(click[0], click[1]));
		int row = board.size();
		int col = board[0].size();
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (board[x][y] == 'M') {
				board[x][y] = 'X';
				return board;
			}
			else if (board[x][y] == 'E') {
				int count = 0;
				if (x > 0 && board[x - 1][y] == 'M') count++;
				if (x > 0 && y > 0 && board[x - 1][y - 1] == 'M') count++;
				if (x > 0 && y < col - 1 && board[x - 1][y + 1] == 'M') count++;
				if (y > 0 && board[x][y - 1] == 'M') count++;
				if (y < col - 1 && board[x][y + 1] == 'M') count++;
				if (y > 0 && x < row - 1 && board[x + 1][y - 1] == 'M') count++;
				if (x < row - 1 && board[x + 1][y] == 'M') count++;
				if (x < row - 1 && y < col - 1 && board[x + 1][y + 1] == 'M') count++;
				if (count > 0) {
					board[x][y] = count + '0';
				}
				else {
					board[x][y] = 'B';
					if (x > 0 && board[x - 1][y] == 'E') q.push(make_pair(x - 1, y));
					if (x > 0 && y > 0 && board[x - 1][y - 1] == 'E') q.push(make_pair(x - 1, y - 1));
					if (x > 0 && y < col - 1 && board[x - 1][y + 1] == 'E') q.push(make_pair(x - 1, y + 1));
					if (y > 0 && board[x][y - 1] == 'E') q.push(make_pair(x, y - 1));
					if (y < col - 1 && board[x][y + 1] == 'E') q.push(make_pair(x, y + 1));
					if (y > 0 && x < row - 1 && board[x + 1][y - 1] == 'E') q.push(make_pair(x + 1, y - 1));
					if (x < row - 1 && board[x + 1][y] == 'E') q.push(make_pair(x + 1, y));
					if (x < row - 1 && y < col - 1 && board[x + 1][y + 1] == 'E') q.push(make_pair(x + 1, y + 1));
				}
			}
		}
		return board;
	}
};