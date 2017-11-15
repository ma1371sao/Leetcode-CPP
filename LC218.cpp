class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> skyLine;
		if (buildings.size() == 0) return skyLine;
		unordered_map<int, int> height_right;
		priority_queue<int> heights;
		int i = 0;
		int x = buildings[0][0];
		while (1) {
			if (i < buildings.size() && x == buildings[i][0]) {
				if (heights.empty()) {
					heights.push(buildings[i][2]);
					height_right[buildings[i][2]] = buildings[i][1];
					skyLine.push_back(make_pair(buildings[i][0], buildings[i][2]));
				}
				else {
					if (buildings[i][2] == heights.top()) {
						height_right[buildings[i][2]] = max(buildings[i][1], height_right[heights.top()]);
					}
					else if (buildings[i][2] > heights.top()) {
						if (skyLine.back().first == buildings[i][0])
							skyLine.pop_back();
						heights.push(buildings[i][2]);
						height_right[buildings[i][2]] = buildings[i][1];
						skyLine.push_back(make_pair(buildings[i][0], buildings[i][2]));
					}
					else {
						heights.push(buildings[i][2]);
						height_right[buildings[i][2]] = max(height_right[buildings[i][2]], buildings[i][1]);
					}
				}
				i++;
			}
			else {
				while (!heights.empty() && height_right[heights.top()] <= x) {
					height_right.erase(heights.top());
					heights.pop();
				}
				if (heights.empty())
					skyLine.push_back(make_pair(x, 0));
				else
					skyLine.push_back(make_pair(x, heights.top()));
			}
			if (!heights.empty() && i < buildings.size())
				x = min(height_right[heights.top()], buildings[i][0]);
			else if (!heights.empty())
				x = height_right[heights.top()];
			else if (i < buildings.size())
				x = buildings[i][0];
			else
				break;
		}
		return skyLine;
	}
};