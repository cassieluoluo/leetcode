public class Solution {
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        int start = 0, end = 0;
        while (end < s.length()) {
            start = end;
            if (isDigit(s.charAt(start))) {
                int openIndex = s.indexOf("[", start);
                int closeIndex = getCloseIndex(s, start);
                int count = Integer.parseInt(s.substring(start, openIndex));
                String sub = s.substring(openIndex + 1, closeIndex);
                appendString(sb, decodeString(sub), count);
                end = closeIndex + 1;
            } else {
                int curr = start;
                while (curr < s.length() && !(isDigit(s.charAt(curr)))) curr++;
                appendString(sb, s.substring(start, curr), 1);
                end = curr;
            }
        }
        return sb.toString();
    }
    
    private boolean isDigit(char c) {  return c >= '0' && c <= '9'; }
    
    private int getCloseIndex(String s, int start) {
        int openCount= 1;
        int curr = s.indexOf("[", start) + 1;
        while (openCount != 0 && curr < s.length()) {
            if (s.charAt(curr) == '[') openCount++;
            else if (s.charAt(curr) ==']') openCount--;
            curr++;
        }
        return curr - 1;
    }
    
    private void appendString(StringBuilder sb, String s, int count) {
        for (int i = 0; i < count; i++) sb.append(s);
    }
} // Author: Cassie
