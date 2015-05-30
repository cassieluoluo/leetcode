/*	
 *	LeetCode Submissions by Xinyu Chen
 *	ZigZag Conversion
 *	https://leetcode.com/problems/zigzag-conversion/
 *	Runtime: 356 ms
 */

public class Solution {
    public String convert(String s, int numRows) {
        if (s.length() <= numRows || numRows == 1) return s;
        char[] ret = new char[s.length()];
        int n = numRows * 2 - 2, index = 0;
        for (int row = 0; row < numRows; row++) {
            if (row == 0 || row == numRows - 1) {
                for (int i = 0; i + row < s.length(); i += n)
                    ret[index++] = s.charAt(row + i);
            } else {
                int i = -n;
                while (true) {
                    i += n;
                    if (i - row >= s.length()) break;
                    if (i - row >= 0) ret[index++] = s.charAt(i - row);
                    if (i + row >= s.length()) break;
                    ret[index++] = s.charAt(i + row);
                }
            }
        }
        return new String(ret);
    }
}