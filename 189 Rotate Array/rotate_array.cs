/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Rotate Array
 *	https://leetcode.com/problems/rotate-array/
 *	Runtime: 538 ms
 */
 
public class Solution {
	public void Rotate(int[] nums, int k)
	{
	    k %= nums.Length;
	    Reverse(nums, 0, nums.Length - 1);
	    Reverse(nums, 0, k - 1);
	    Reverse(nums, k, nums.Length - 1);
	}

	public void Reverse(int[] nums, int begin, int end)
	{
	    while (begin < end)
	    {
		var temp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = temp;
		begin++;
		end--;
	    }
	}
}