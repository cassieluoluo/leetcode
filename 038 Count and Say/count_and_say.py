class Solution: # Author: XC
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        s = '1'
        result = []
        for i in range(n - 1):
            count = 1
            current = s[0]
            for j in range(1, len(s)):
                if s[j] == current:
                    count += 1
                else:
                    result.append(str(count))
                    result.append(current)
                    current = s[j]
                    count = 1
            result.append(str(count))
            result.append(current)
            s = ''.join(result)
            result = []
        return s
