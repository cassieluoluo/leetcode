public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] map = new int[26];
        int[] visited = new int[26];
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();
        for (char c : chars) {
            map[c - 'a']++;
        }
        
        for (char c : chars) {
            if (visited[c - 'a'] == 1) {
                map[c - 'a']--;
                continue;
            }
            map[c - 'a']--;
            visited[c - 'a'] = 1;
            
            while (sb.length() > 0 && c - 'a' < sb.charAt(sb.length() - 1) - 'a' ) {
                int prev = sb.charAt(sb.length() - 1) - 'a';
                if (map[prev] > 0) {
                    sb.deleteCharAt(sb.length() - 1);
                    visited[prev] = 0;
                } else {
                    break;
                }
            }
            sb.append(c);
            visited[c - 'a'] = 1;
        }
        return sb.toString();
    }
} // Author: Cassie
