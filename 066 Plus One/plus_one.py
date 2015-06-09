# LeetCode Submissions by Xinyu Chen
# Plus One
# https://leetcode.com/problems/plus-one/
# Runtime: 44 ms
 
class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
        if len(str) == 0:
            return 0
        index = 0
        while str[index] == ' ' or str[index] == '\t' or str[index] == '\r' or str[index] == '\n':
            index += 1
            if index == len(str):
                return 0
        negative = False
        if str[index] == '-':
            negative = True
            index += 1
        elif str[index] == '+':
            index += 1
        elif str[index] < '0' or str[index] > '9':
            return 0
        buffer = []
        while '0' <= str[index] <= '9':
            buffer.append(str[index])
            index += 1
            if index == len(str):
                break
        res = 0
        for n in buffer:
            res *= 10
            res += ord(n) - ord('0')
            if negative and res > (2**31):
                return -(2**31)
            if not negative and res > (2**31 - 1):
                return 2**31 - 1
        if negative:
            return -res
        else:
            return res