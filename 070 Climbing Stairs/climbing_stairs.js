/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Climbing Stairs
 *	https://leetcode.com/problems/climbing-stairs/
 *	Runtime: 132 ms
 */
 
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    var a = 1, b = 2, c = 0;
    for (var i = 3; i <= n; i++) {
    	c = a + b;
    	a = b;
    	b = c;
    }
    return c;
};