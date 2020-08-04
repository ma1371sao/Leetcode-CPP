class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) return res;
        int col = matrix[0].size();
        
        int level = 0;
        while (res.size() < row * col) {
            for (int c = level; res.size() < row * col && c < col - level; c++)
                res.push_back(matrix[level][c]);
            for (int r = level + 1; res.size() < row * col && r < row - level; r++)
                res.push_back(matrix[r][col - 1 - level]);
            for (int c = col - 2 - level; res.size() < row * col && c >= level; c--)
                res.push_back(matrix[row - 1 - level][c]);
            for (int r = row - 2 - level; res.size() < row * col && r > level; r--)
                res.push_back(matrix[r][level]);
            level++;
        }
        return res;
    }
};
