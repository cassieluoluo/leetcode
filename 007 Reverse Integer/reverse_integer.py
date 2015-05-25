# LeetCode Submissions by Xinyu Chen
# Reverse Integer
# https://leetcode.com/problems/reverse-integer/
# Runtime: 68 ms

class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        res = 0
        data = abs(x)
        while data > 0:
            res *= 10
            res += data % 10
            data //= 10
        if res > (2**31 - 1):
            return 0
        if x >= 0:
            return res
        else:
            return -res