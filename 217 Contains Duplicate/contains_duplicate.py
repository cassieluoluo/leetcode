class Solution: # Author: XC
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        s = set(nums)
        if len(s) < len(nums):
            return True
        return False
