/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Number of 1 Bits
 *	https://leetcode.com/problems/number-of-1-bits/
 *	Runtime: 292 ms
 */
 
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}
