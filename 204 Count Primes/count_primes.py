# LeetCode Submissions by Xinyu Chen
# Count Primes
# https://leetcode.com/problems/count-primes/
# Runtime: 868 ms

class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n < 2:
            return 0
        numbers = [True] * n
        numbers[0] = False
        numbers[1] = False
        p = 2
        while p < math.sqrt(n):
            if numbers[p]:
                for i in range(p*p, n, p):
                    numbers[i] = False
            p += 1
        
        counter = 0
        for i in range(n):
            if numbers[i]:
                counter += 1
        return counter