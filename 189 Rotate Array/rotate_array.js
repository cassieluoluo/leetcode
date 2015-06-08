/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Rotate Array
 *	https://leetcode.com/problems/rotate-array/
 *	Runtime: 188 ms
 */
 
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k %= nums.length;
    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);
};

var reverse = function(nums, begin, end) {
    while (begin < end) {
        var temp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = temp;
        begin++; end--;
    }
}