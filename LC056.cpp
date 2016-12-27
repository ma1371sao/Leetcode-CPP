/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
bool cmp(Interval x, Interval y)
{
	return x.start<y.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		if (intervals.size() == 0)
			return ans;
		sort(intervals.begin(), intervals.end(), cmp);
		int start = 0;
		int end = 0;
		int pos = 0;
		while (pos<intervals.size())
		{
			start = intervals[pos].start;
			end = intervals[pos].end;
			for (; pos + 1<intervals.size() && end >= intervals[pos + 1].start; pos++)
			{
				if (end<intervals[pos + 1].end)
					end = intervals[pos + 1].end;
			}
			pos++;
			Interval x(start, end);
			ans.push_back(x);
		}
		return ans;
	}
};