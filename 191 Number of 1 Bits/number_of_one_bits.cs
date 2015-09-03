/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Number of 1 Bits
 *	https://leetcode.com/problems/number-of-1-bits/
 *	Runtime: 292 ms
 */
 
public class Solution {
    public int HammingWeight(uint n) {
        uint count = 0;
        while (n > 0)
        {
            count += n & 1;
            n >>= 1;
        }
        return (int)count;
    }
}
