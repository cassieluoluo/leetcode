/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Rotate Array
 *	https://leetcode.com/problems/rotate-array/
 *	Runtime: 8 ms
 */
 
void reverse(int* nums, int begin, int end) {
	while (begin < end) {
		int temp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = temp;
		begin++; end--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}