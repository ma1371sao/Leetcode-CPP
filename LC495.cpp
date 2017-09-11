class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.size() == 0) return 0;
		int endTime = timeSeries[0] + duration;
		int totalTime = duration;
		for (int i = 1; i < timeSeries.size(); i++) {
			if (timeSeries[i] >= endTime) {
				totalTime += duration;
				endTime = timeSeries[i] + duration;
			}
			else {
				totalTime += timeSeries[i] + duration - endTime;
				endTime = timeSeries[i] + duration;
			}
		}
		return totalTime;
	}
};