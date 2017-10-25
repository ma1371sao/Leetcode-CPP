class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		vector<int> height(n, 0);
		vector<int> left(n, 0);
		vector<int> right(n, n);
		int maxArea = 0;
		for (int r = 0; r < m; r++) {
			int curLeft = 0;
			int curRight = n;
			for (int c = 0; c < n; c++) {
				if (matrix[r][c] == '1') {
					height[c]++;
					left[c] = max(left[c], curLeft);
				}
				else {
					height[c] = 0;
					curLeft = c + 1;
					left[c] = 0;
				}
			}
			for (int c = n - 1; c >= 0; c--) {
				if (matrix[r][c] == '1')
					right[c] = min(right[c], curRight);
				else {
					curRight = c;
					right[c] = n;
				}
			}

			for (int c = 0; c < n; c++) {
				maxArea = max(maxArea, height[c] * (right[c] - left[c]));
			}
		}
		return maxArea;
	}
};