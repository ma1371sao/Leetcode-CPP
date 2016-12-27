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
		int n = intervals.size();
		vector<Interval> ans;
		if (n == 0)
		{
			ans.push_back(newInterval);
			return ans;
		}
		for (int k = 0; k<n;)
		{
			if (intervals[k].end<newInterval.start)
			{
				ans.push_back(intervals[k]);
				if (k == n - 1)
					ans.push_back(newInterval);
				else
				{
					if (intervals[k + 1].start>newInterval.end)
					{
						ans.push_back(newInterval);
						for (int i = k + 1; i<n; i++)
							ans.push_back(intervals[i]);
						break;
					}
				}
				k++;
			}
			else
			{
				int start = intervals[k].start;
				if (start>newInterval.start)
					start = newInterval.start;
				int end = newInterval.end;
				if (intervals[k].start>newInterval.end)
					end = newInterval.end;
				else if (end <= intervals[k].end)
				{
					end = intervals[k].end;
					k++;
				}
				else {
					k++;
					for (; k<n && end >= intervals[k].start; k++)
					{
						if (end<intervals[k].end)
							end = intervals[k].end;
					}
				}
				Interval val(start, end);
				ans.push_back(val);
				for (; k<n; k++)
					ans.push_back(intervals[k]);
				break;
			}
		}
		return ans;
	}
};