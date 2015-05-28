/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Palindrome Number 
 *	https://leetcode.com/problems/palindrome-number/
 *	Runtime: 144 ms
 */

public class Solution {
    public bool IsPalindrome(long x) {
        if (x == 0) return true;
        if (x < 0) return false;
        int length = (int) Math.Ceiling(Math.Log10(x + 1));
        long b = (long) Math.Pow(10, length - 1);
        for (int i = 0; i < length/2; i++)
        {
            if (x%10 != x/b) return false;
            x %= b;
            x /= 10;
            b /= 100;
        }
        return true;
    }
}