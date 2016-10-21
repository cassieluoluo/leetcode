/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareInterval(Interval i1, Interval i2) {
    return i1.start < i2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareInterval);
        int index = 0, left, right;
		vector<Interval> result;
		while (index < intervals.size()) {
			left = intervals[index].start;
			right = intervals[index].end;
			while (++index < intervals.size()) {
				if (intervals[index].start <= right) {
					right = max(right, intervals[index].end);
				}
				else break;
			}
			result.push_back(Interval(left, right));
		}
		return result;
    }
}; // Author: XC
