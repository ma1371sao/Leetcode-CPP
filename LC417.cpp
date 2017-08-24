class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> res;
		if (matrix.size() == 0) return res;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			pacific[i][0] = true;
			atlantic[i][n - 1] = true;
		}
		for (int i = 0; i < n; i++) {
			pacific[0][i] = true;
			atlantic[m - 1][i] = true;
		}
		for (int c = 0; c < n; c++) {
			searchArrival(0, c, matrix, pacific);
			searchArrival(m - 1, c, matrix, atlantic);
		}
		for (int r = 0; r < m; r++) {
			searchArrival(r, 0, matrix, pacific);
			searchArrival(r, n - 1, matrix, atlantic);
		}
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < n; c++) {
				if (pacific[r][c] && atlantic[r][c])
					res.push_back(make_pair(r, c));
			}
		}
		return res;
	}
	void searchArrival(int r, int c, vector<vector<int>>& matrix, vector<vector<bool>>& arrival) {
		int m = matrix.size();
		int n = matrix[0].size();
		if (c + 1 < n && !arrival[r][c + 1] && matrix[r][c + 1] >= matrix[r][c]) {
			arrival[r][c + 1] = true;
			searchArrival(r, c + 1, matrix, arrival);
		}
		if (r + 1 < m && !arrival[r + 1][c] && matrix[r + 1][c] >= matrix[r][c]) {
			arrival[r + 1][c] = true;
			searchArrival(r + 1, c, matrix, arrival);
		}
		if (c - 1 >= 0 && !arrival[r][c - 1] && matrix[r][c - 1] >= matrix[r][c]) {
			arrival[r][c - 1] = true;
			searchArrival(r, c - 1, matrix, arrival);
		}
		if (r - 1 >= 0 && !arrival[r - 1][c] && matrix[r - 1][c] >= matrix[r][c]) {
			arrival[r - 1][c] = true;
			searchArrival(r - 1, c, matrix, arrival);
		}
	}
};