class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0) return 0;
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        unordered_set<int> visited;
        visited.insert(1);
        
        while (!q.empty()) {
            int pos = q.front().first;
            int count = q.front().second;
            q.pop();
            if (pos == n * n) return count;
            
            for (int i = 1; i <= 6 && pos + i <= n * n; i++) {
                int nxt = pos + i;
                int r = (nxt - 1) / n, c = (nxt - 1) % n;
                if (r % 2 == 1) c = n - 1 - c;
                r = n - 1 - r;
                if (board[r][c] == -1) {
                    if (!visited.count(nxt)) {
                        q.push(make_pair(nxt, count + 1));
                        visited.insert(nxt);
                    }
                } else if (!visited.count(board[r][c])) {
                    q.push(make_pair(board[r][c], count + 1));
                    visited.insert(board[r][c]);
                }
            }
        }
        return -1;
    }
};
