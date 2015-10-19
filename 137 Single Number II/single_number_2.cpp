/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Single Number II
 *	https://leetcode.com/problems/single-number-ii/
 *	Runtime: 12 ms
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, temp;
        for (auto n : nums) {
            twos |= ones & n;
            ones ^= n;
            temp = ~(ones & twos);
            ones &= temp;
            twos &= temp;
        }
        return ones;
    }
};