# LeetCode Submissions by Xinyu Chen
# Climbing Stairs
# https://leetcode.com/problems/climbing-stairs/
# Runtime: 40 ms
 
class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self, n):
        if n == 1:
            return 1
        if n == 2:
            return 2
        a = 1
        b = 2
        c = 0
        for i in range(2, n):
            c = a + b
            a = b
            b = c
        return c