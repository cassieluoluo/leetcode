/**
 * Definition for an interval.
 * public class Interval {
 *     public int start;
 *     public int end;
 *     public Interval() { start = 0; end = 0; }
 *     public Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public IList<Interval> Merge(IList<Interval> intervals) {
        var sorted = intervals.OrderBy(x => x.start).ToList();
        var result = new List<Interval>();
        foreach (var i in sorted) {
            if (result.Count == 0) result.Add(i);
            else {
                int end = result.Last().end;
                if (i.start > end) result.Add(i);
                else result.Last().end = Math.Max(i.end, end);
            }
        }
        return result;
        
    }
} // Author: XC
