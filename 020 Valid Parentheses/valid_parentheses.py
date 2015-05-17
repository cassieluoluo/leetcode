# LeetCode Submissions by Xinyu Chen
# Valid Parentheses
# https://leetcode.com/problems/valid-parentheses/
# Runtime: 46 ms

class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        st = []
        pairs = {')':'(', '}':'{', ']':'['}
        for c in s:
            if c == '(' or c == '{' or c == '[':
                st.append(c)
            elif len(st) == 0:
                return False
            else:
                if pairs[c] != st.pop():
                    return False
        if len(st) == 0:
            return True
        return False