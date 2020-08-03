class Solution {
public:
    int row, col, longestIncPath;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if (row == 0) return 0;
        col = matrix[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> dp(row, vector<int>(col, 1));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                dfs(matrix, visited, dp, r, c);
            }
        }
        
        return longestIncPath;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& dp, int r, int c) {
        if (visited[r][c]) return dp[r][c];

        visited[r][c] = true;
        if (r > 0 && matrix[r - 1][c] > matrix[r][c]) dp[r][c] = max(dp[r][c], dfs(matrix, visited, dp, r - 1, c) + 1);
        if (r < row - 1 && matrix[r + 1][c] > matrix[r][c]) dp[r][c] = max(dp[r][c], dfs(matrix, visited, dp, r + 1, c) + 1);
        if (c > 0 && matrix[r][c - 1] > matrix[r][c]) dp[r][c] = max(dp[r][c], dfs(matrix, visited, dp, r, c - 1) + 1);
        if (c < col - 1 && matrix[r][c + 1] > matrix[r][c]) dp[r][c] = max(dp[r][c], dfs(matrix, visited, dp, r, c + 1) + 1);
        if (longestIncPath < dp[r][c])
            longestIncPath = dp[r][c];
        return dp[r][c];
    }
};
