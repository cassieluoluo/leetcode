/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {	// Author: Xinyu Chen
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 0; i < (int)intervals.size() - 1; ++i) {
            if (intervals[i].end > intervals[i + 1].start) return false;
        }
        return true;
    }
    
    static bool compare(Interval& ia, Interval& ib) {
        return ia.start < ib.start;
    }
};
