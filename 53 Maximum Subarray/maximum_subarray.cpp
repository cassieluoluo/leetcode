/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Maximum Subarray
 *	https://leetcode.com/problems/maximum-subarray/
 *	Runtime: 8 ms
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int cursum = 0;
        for (auto n : nums) {
            cursum += n;
            maxsum = max(maxsum, cursum);
            if (cursum < 0) cursum = 0;
        }
        return maxsum;
    }
};