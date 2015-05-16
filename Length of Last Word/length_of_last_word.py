# LeetCode Submissions by Xinyu Chen
# Length of Last Word
# https://leetcode.com/problems/length-of-last-word/
# Runtime: 54 ms

class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        words = s.split()
        if len(words) == 0:
            return 0
        else:
            return len(words[-1])