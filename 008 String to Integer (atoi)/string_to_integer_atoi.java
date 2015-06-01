/*	
 *	LeetCode Submissions by Xinyu Chen
 *	String to Integer (atoi)
 *	https://leetcode.com/problems/string-to-integer-atoi/
 *	Runtime: 424 ms
 */
 
public class Solution {
    public int myAtoi(String str) {
        if (str.length() == 0) return 0;
        int index = 0;
        while (str.charAt(index) == ' '
                || str.charAt(index) == '\t'
                || str.charAt(index) == '\r'
                || str.charAt(index) == '\n')
            if (++index == str.length()) return 0;

        boolean negative = false;
        if (str.charAt(index) == '-') {
            negative = true;
            index++;
        } else if (str.charAt(index) == '+') {
            index++;
        } else if (str.charAt(index) < '0' || str.charAt(index) > '9') return 0;

        char[] buffer = new char[str.length() - index];
        int cnt = 0;
        while (str.charAt(index) >= '0' && str.charAt(index) <= '9') {
            buffer[cnt++] = str.charAt(index);
            if (++index >= str.length()) break;
        }
        long res = 0;
        for (int i = 0; i < cnt; i++) {
            res *= 10;
            res += buffer[i] - '0';
            if (negative && -res < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            if (!negative && res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        }
        return negative ? -(int)res : (int)res;
    }
}