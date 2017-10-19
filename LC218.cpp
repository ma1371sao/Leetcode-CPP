class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> pts;
		if (buildings.size() == 0)
			return pts;
		int n = buildings.size();
		int rightSide = 0;
		for (int i = 0; i < n; i++) {
			rightSide = max(rightSide, buildings[i][1]);
		}
		unordered_map<int, int> height_right;
		int preHeight = 0;
		int height = 0;
		int cur = 0;
		priority_queue<int> maxHeight;
		int x = buildings[0][0];
		while (x <= rightSide) {
			if (cur < buildings.size() && x == buildings[cur][0]) {
				maxHeight.push(buildings[cur][2]);
				height_right[buildings[cur][2]] = buildings[cur][1];
				cur++;
			}
			if (x < height_right[maxHeight.top()]) {
				height = maxHeight.top();
				if (pts.empty()) {
					pts.push_back(make_pair(x, height));
				}
				else if (height > preHeight) {
					if (pts.back().first == x)
						pts.pop_back();
					pts.push_back(make_pair(x, height));
				}
			}
			else {
				while (!maxHeight.empty() && height_right[maxHeight.top()] <= x) {
					maxHeight.pop();
				}
				if (maxHeight.empty()) height = 0;
				else height = maxHeight.top();
				if (height != preHeight)
					pts.push_back(make_pair(x, height));
			}
			preHeight = height;
			if (cur < buildings.size() || !maxHeight.empty()) {
				if (cur < buildings.size() && !maxHeight.empty())
					x = min(buildings[cur][0], height_right[maxHeight.top()]);
				else if (maxHeight.empty())
					x = buildings[cur][0];
				else
					x = height_right[maxHeight.top()];
			}
			else break;
		}
		return pts;
	}
};