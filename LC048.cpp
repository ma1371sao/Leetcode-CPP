class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return;
		int n = matrix.size();
		int c, r;
		int a[1000][1000];
		for (c = 0; c<n; c++)
			for (r = n - 1; r >= 0; r--)
				a[c][n - 1 - r] = matrix[r][c];
		for (r = 0; r<n; r++)
			for (c = 0; c<n; c++)
				matrix[r][c] = a[r][c];
	}
};