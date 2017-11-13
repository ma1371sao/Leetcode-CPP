class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> index;
		int maxArea = 0;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++) {
			while (!index.empty() && heights[i] <= heights[index.top()]) {
				int h = heights[index.top()];
				index.pop();
				int l = index.empty() ? i : i - 1 - index.top();
				maxArea = max(maxArea, h * l);
			}
			index.push(i);
		}
		return maxArea;
	}
};