/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Palindrome Number 
 *	https://leetcode.com/problems/palindrome-number/
 *	Runtime: 480 ms
 */

public class Solution {
    public boolean isPalindrome(long x) {
        if (x == 0) return true;
        if (x < 0) return false;
        int len = (int)Math.ceil(Math.log10(x + 1));
        long base = (int)Math.pow(10, len - 1);
        for (int i = 0; i < len / 2; i++) {
            if (x % 10 != x / base) return false;
            x %= base;
            x /= 10;
            base /= 100;
        }
        return true;
    }
}