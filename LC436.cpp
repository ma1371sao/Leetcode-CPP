/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		vector<int> rightIntervals;
		if (intervals.size() == 0) return rightIntervals;
		map<int, int> startToIndex;
		for (int i = 0; i < intervals.size(); i++) {
			startToIndex[intervals[i].start] = i;
		}
		for (int i = 0; i < intervals.size(); i++) {
			auto it = startToIndex.lower_bound(intervals[i].end);
			if (it == startToIndex.end()) rightIntervals.push_back(-1);
			else rightIntervals.push_back(it->second);
		}
		return rightIntervals;
	}
};