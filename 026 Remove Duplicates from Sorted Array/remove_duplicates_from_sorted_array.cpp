/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Remove Duplicates from Sorted Array
 *	https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *	Runtime: 32 ms
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pt = 0;
        if (nums.size() < 2) return nums.size();
        for (auto n : nums)
            if (nums[pt] != n) nums[++pt] = n;
        return pt + 1;
    }
};