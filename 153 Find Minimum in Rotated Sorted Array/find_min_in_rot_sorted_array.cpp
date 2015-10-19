/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Find Minimum in Rotated Sorted Array
 *	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *	Runtime: 4 ms
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[lo] > nums[mid]) hi = mid;
            else if (nums[hi] < nums[mid]) lo = mid + 1;
            else break;
        }
        return nums[lo];
    }
};
