/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Number of 1 Bits
 *	https://leetcode.com/problems/number-of-1-bits/
 *	Runtime: 16 ms
 */
 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += n % 2;
            n /= 2;
        }
        return count;
    }
};
