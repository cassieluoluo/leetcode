/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Reverse Integer
 *	https://leetcode.com/problems/reverse-integer/
 *	Runtime: 264 ms
 */

public class Solution {
    public int reverse(int x) {
        long res = 0;
        int input = Math.abs(x);
        while (input > 0) {
            res *= 10;
            res += input % 10;
            input /= 10;
        }
        if (res > Integer.MAX_VALUE) return 0;
        return x >= 0 ? (int)res : -(int)res;
    }
}