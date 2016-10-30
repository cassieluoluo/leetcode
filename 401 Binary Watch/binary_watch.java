public class Solution {
    public List<String> readBinaryWatch(int num) {
        int[] map = new int[] {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
        List<String> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        int[] visited = new int[10];
        helper(num, 0, res, list, map, visited);
        //Collections.
        return res;
        
    }
    
    private void helper(int num, int pos, List<String> res, List<Integer> list, int[] map, int[] visited) {
        if (list.size() == num) {
            int min = 0;
            int hour = 0;
            for (int digit : list) {
                if (digit < 4) {
                    hour += map[digit];
                    if (hour < 0 || hour > 11) return;
                } else {
                    min += map[digit];
                    if (min < 0 || min > 59) return;
                }
            }
            if (min < 10) {
                res.add(hour + ":" + "0" + min);
            } else {
                res.add(hour + ":" + min);
            }
            return;
        }
        for (int i = pos; i < 10; i++) {
            if (visited[i] != 0) 
                continue;
            list.add(i);
            visited[i] = 1;
            
            helper(num, i + 1, res, list, map, visited);
            list.remove(list.size() - 1);
            visited[i] = 0;
        }
    }
} // Author: Cassie
