# LeetCode Submissions by Xinyu Chen
# Contains Duplicate
# https://leetcode.com/problems/contains-duplicate/
# Runtime: 56 ms

class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        s = set(nums)
        if len(s) < len(nums):
            return True
        return False