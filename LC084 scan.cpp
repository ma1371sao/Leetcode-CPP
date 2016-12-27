class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n == 0)    return 0;
		long long max = 0;
		int right[100000];
		int left[100000];
		right[n - 1] = 1;
		left[0] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (heights[i]>heights[i + 1])
				right[i] = 1;
			else {
				int j;
				for (j = i + 1; j<n && heights[i] <= heights[j]; j = j + right[j]);
				right[i] = j - i;
			}
		}
		for (int i = 1; i<n; i++) {
			if (heights[i]>heights[i - 1])
				left[i] = 1;
			else {
				int j;
				for (j = i - 1; j >= 0 && heights[i] <= heights[j]; j = j - left[j]);
				left[i] = i - j;
			}
		}
		for (int i = 0; i<n; i++) {
			int s = heights[i] * (right[i] + left[i] - 1);
			if (s>max)
				max = s;
		}
		return max;
	}
};