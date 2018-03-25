class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> matrix) {
        int r = matrix.size();
        if (r == 0) return;
        int c = matrix[0].size();
        sum = vector<vector<int>>(r, vector<int>(c + 1, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                sum[i][j + 1] = sum[i][j] + matrix[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sumRec = 0;
        for (int i = row1; i <= row2; i++) {
            sumRec += sum[i][col2 + 1] - sum[i][col1];
        }
        return sumRec;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
