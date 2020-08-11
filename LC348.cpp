class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): rows(n), cols(n), diag(0), rdiag(0) {}

    int move(int row, int col, int player) {
        int n = rows.size();
        int add = 1;
        if (player == 2) add = -1;
        rows[row] += add;
        cols[col] += add;
        if (row == col) diag += add;
        if (row + col == n - 1) rdiag += add;
        if (rows[row] == n * add || cols[rol] == n * add || diag == n * add || rdiag == n * add)
            return player;
        return 0;
    }

private:
    vector<int> rows, cols;
    int diag, rdiag;
};
