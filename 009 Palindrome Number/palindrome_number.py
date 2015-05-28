# LeetCode Submissions by Xinyu Chen
# Palindrome Number 
# https://leetcode.com/problems/palindrome-number/
# Runtime: 480 ms

class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if x == 0:
            return True
        if x < 0:
            return False
        length = math.ceil(math.log10(x + 1))
        base = 10 ** (length - 1)
        for i in range(0, int(length / 2)):
            if x % 10 != x // base:
                return False
            x %= base
            x //= 10
            base //= 100
        return True