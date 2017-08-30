bool cmp(const pair<int, int> point1, const pair<int, int> point2) {
	return point1.second < point2.second;
}
class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0) return 0;
		int min = 1;
		sort(points.begin(), points.end(), cmp);
		int rightSide = points[0].second;
		for (int i = 1; i < points.size(); i++) {
			if (points[i].first > rightSide) {
				rightSide = points[i].second;
				min++;
			}
		}
		return min;
	}
};