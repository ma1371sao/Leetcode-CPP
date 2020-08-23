class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n - r; c++) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[n - c - 1][n - r - 1];
                matrix[n - c - 1][n - r - 1] = tmp;
            }
        }
        
        for (int r = 0; r < n / 2; r++) {
            for (int c = 0; c < n; c++) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[n - r - 1][c];
                matrix[n - r - 1][c] = tmp;
            }
        }
    }
};
