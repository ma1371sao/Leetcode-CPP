/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
bool cmp(const Interval& a, const Interval& b) {
	return a.start < b.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.size() == 0) return res;
		sort(intervals.begin(), intervals.end(), cmp);
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start <= end) end = max(end, intervals[i].end);
			else {
				Interval itv(start, end);
				res.push_back(itv);
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		Interval itv(start, end);
		res.push_back(itv);
		return res;
	}
};