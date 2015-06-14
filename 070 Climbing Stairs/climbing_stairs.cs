/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Climbing Stairs
 *	https://leetcode.com/problems/climbing-stairs/
 *	Runtime: 60 ms
 */
 
public class Solution {
    public int ClimbStairs(int n) {
        if (n == 1) return 1;
    	if (n == 2) return 2;
    	int a = 1, b = 2, c = 0;
    	for (int i = 3; i <= n; i++) {
    		c = a + b;
    		a = b;
    		b = c;
    	}
    	return c;
    }
}