public class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int start = 0, end = 0, count = 0;
        int maxLen = 0;
        int[] map = new int[128];
        while (end < s.length()) {
            if (map[s.charAt(end)] == 0) count++;
            map[s.charAt(end)]++;
            end++;
            while (count > k) {
                map[s.charAt(start)]--;
                if (map[s.charAt(start)] == 0) count--;
                start++;
            }
            maxLen = Math.max(maxLen, end - start);
        }
        return maxLen;
    }
} // Author: Cassie
