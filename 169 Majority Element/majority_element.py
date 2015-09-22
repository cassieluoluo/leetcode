# LeetCode Submissions by Xinyu Chen
# Majority Element
# https://leetcode.com/problems/majority-element/
# Runtime: 68 ms

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = 0
        current = 0
        for n in nums:
            if counter == 0:
                current = n
            if current == n:
                counter += 1
            else:
                counter -= 1
        return current
# The idea behind this solution is:
#	Removing two distinct elements in the array does not change the majority element