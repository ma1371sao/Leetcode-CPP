class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = matrix.size();
        if (r == 0) return res;
        int c = matrix[0].size();
        vector<vector<bool>> visit(r, vector<bool>(c, false));
        int direction = 0;
        int i = 0;
        int j = 0;
        res.push_back(matrix[0][0]);
        visit[0][0] = true;
        while (res.size() < r * c) {
            if (direction == 0) {
                if (j + 1 < c && !visit[i][j + 1]) {
                    j++;
                    res.push_back(matrix[i][j]);
                    visit[i][j] = true;
                }
                else direction = 1;
            }
            else if (direction == 1) {
                if (i + 1 < r && !visit[i + 1][j]) {
                    i++;
                    res.push_back(matrix[i][j]);
                    visit[i][j] = true;
                }
                else direction = 2;
            }
            else if (direction == 2) {
                if (j - 1 >= 0 && !visit[i][j - 1]) {
                    j--;
                    res.push_back(matrix[i][j]);
                    visit[i][j] = true;
                }
                else direction = 3;
            }
            else if (direction == 3) {
                if (i - 1 >= 0 && !visit[i - 1][j]) {
                    i--;
                    res.push_back(matrix[i][j]);
                    visit[i][j] = true;
                }
                else direction = 0;
            }
        }
        return res;
    }
};
