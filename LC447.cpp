class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		if (points.size() < 3) return 0;
		int num = 0;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<int, int> disRecord;
			for (int j = 0; j < points.size(); j++) {
				int dis = getDistance(points[i], points[j]);
				if (disRecord.find(dis) == disRecord.end()) {
					disRecord[dis] = 0;
				}
				num += disRecord[dis] * 2;
				disRecord[dis]++;
			}
		}
		return num;
	}
	int getDistance(pair<int, int> p1, pair<int, int> p2) {
		int distance = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
		return distance;
	}
};