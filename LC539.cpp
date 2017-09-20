class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		if (timePoints.size() == 0) return 0;
		vector<int> time;
		for (int i = 0; i < timePoints.size(); i++) {
			time.push_back(stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3)));
		}
		int min = INT_MAX;
		sort(time.begin(), time.end());
		for (int i = 0; i < time.size(); i++) {
			if (i + 1 < time.size() && time[i + 1] - time[i] < min) min = time[i + 1] - time[i];
			else if (time[0] + 24 * 60 - time[i] < min) {
				min = time[0] + 24 * 60 - time[i];
			}
		}
		return min;
	}
};