/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Number of 1 Bits
 *	https://leetcode.com/problems/number-of-1-bits/
 *	Runtime: 4 ms
 */
 
int hammingWeight(uint32_t n) {
    int count = 0;
	while (n > 0) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}
