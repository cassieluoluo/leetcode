public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<>();
        if (intervals == null || intervals.size() == 0) return res;
       
        Collections.sort(intervals, new Comparator<Interval>() {
           public int compare (Interval a, Interval b) {
               return a.start - b.start;
           }
        });
        System.out.println(intervals.get(0));
        Interval temp = intervals.get(0);
        res.add(temp);
        for (int i = 1; i < intervals.size(); i++) {
            Interval curt = intervals.get(i);
            if (temp.end >= curt.start) {
                temp.end = Math.max(temp.end, curt.end);
            } else {
                temp = curt;
                res.add(temp);
            }
        }
        return res;
    }
} // Author: Cassie
