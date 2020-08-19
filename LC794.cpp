class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int diag = 0;
        int rDiag = 0;
        int numX = 0;
        int numO = 0;
        bool xWin = false;
        bool oWin = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    numX++;
                    rows[i]++;
                    cols[j]++;
                    if (i == j) diag++;
                    if (i + j == 2) rDiag++;
                    if (rows[i] == 3 || cols[j] == 3 || diag == 3 || rDiag == 3) 
                        xWin = true;
                } else if (board[i][j] == 'O') {
                    numO++;
                    rows[i]--;
                    cols[j]--;
                    if (i == j) diag--;
                    if (i + j == 2) rDiag--;
                    if (rows[i] == -3 || cols[j] == -3 || diag == -3 || rDiag == -3) 
                        oWin = true;
                }
            }
        }
        
        if (numX - numO != 0 && numX - numO != 1) return false;
        if (xWin && oWin) return false;
        if (xWin) {
            if (numX - numO != 1) return false;
        }
        if (oWin) {
            if (numX != numO) return false;
        }
        return true;
    }
};
