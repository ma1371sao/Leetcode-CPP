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
        int start = newInterval.start;
        int end = newInterval.end;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (inserted) {
                res.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].end < start)
                res.push_back(intervals[i]);
            else if (end < intervals[i].start) {
                Interval it(start, end);
                res.push_back(it);
                res.push_back(intervals[i]);
                inserted = true;
            }
            else {
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            }
        }
        if (!inserted) {
            Interval it(start, end);
            res.push_back(it);
        }
        return res;
    }
};