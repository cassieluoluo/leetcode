class Solution:	# Author: Xinyu Chen
    # @param {string} s
    # @return {boolean}
    def isPalindrome(self, s):
        if len(s) == 0:
            return True
        s = s.lower()
        i = 0
        j = len(s) - 1
        while i < j:
            while not s[i].isalnum():
                i += 1
                if i >= j:
                    return True
            while not s[j].isalnum():
                j -= 1
                if j <= i:
                    return True
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
