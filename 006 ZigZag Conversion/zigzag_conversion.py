# LeetCode Submissions by Xinyu Chen
# ZigZag Conversion
# https://leetcode.com/problems/zigzag-conversion/
# Runtime: 156 ms

class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        if numRows == 1 or len(s) <= numRows:
            return s
        n = 2 * numRows - 2
        ret = []
        for row in range(0, numRows):
            if row == 0 or row == numRows - 1:
                for i in range(0, len(s) - row, n):
                    ret.append(s[row + i])
            else:
                i = -n
                while True:
                    i += n
                    if i - row >= len(s):
                        break
                    if i - row >= 0:
                        ret.append(s[i - row])
                    if i + row >= len(s):
                        break
                    else:
                        ret.append(s[i + row])
        return ''.join(ret)
