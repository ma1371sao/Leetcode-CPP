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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		if (intervals.size() == 0) {
			res.push_back(newInterval);
			return res;
		}
		int start = newInterval.start;
		int end = newInterval.end;
		bool hasMerged = false;
		if (newInterval.end < intervals[0].start) {
			res.push_back(newInterval);
			hasMerged = true;
		}
		for (int i = 0; i < intervals.size(); i++) {
			if (intervals[i].end < start) {
				res.push_back(intervals[i]);
			}
			else if (intervals[i].start > end) {
				if (!hasMerged) {
					hasMerged = true;
					Interval merged(start, end);
					res.push_back(merged);
				}
				res.push_back(intervals[i]);
			}
			else {
				start = min(start, intervals[i].start);
				end = max(end, intervals[i].end);
			}
		}
		if (!hasMerged) {
			Interval merged(start, end);
			res.push_back(merged);
		}
		return res;
	}
};