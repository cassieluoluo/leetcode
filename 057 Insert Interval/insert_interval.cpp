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
        int pos = 0, len = intervals.size();
        vector<Interval> result;
        while (pos < len && intervals[pos].end < newInterval.start) result.push_back(intervals[pos++]);
        if (pos == len) {
            result.push_back(newInterval);
            return result;
        }
        if (newInterval.start > intervals[pos].start) swap(newInterval, intervals[pos]);
        result.push_back(newInterval);
        for (; pos < len; pos++) {
            int end = result.back().end;
            if (intervals[pos].start > end) result.push_back(intervals[pos]);
            else result.back().end = max(result.back().end, intervals[pos].end);
        }
        return result;
    }
}; // Author: XC
