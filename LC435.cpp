/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
bool cmp(Interval i1, Interval i2) {
	return i1.end < i2.end;
}
class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() < 2) return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		vector<int> dp(intervals.size(), 0);
		for (int i = 1; i < intervals.size(); i++) {
			int notRemove = 0;
			int last = i - 1;
			for (; last >= 0 && intervals[i].start < intervals[last].end; last--, notRemove++);
			dp[i] = min(notRemove + dp[last], 1 + dp[i - 1]);
		}
		return dp.back();
	}
};