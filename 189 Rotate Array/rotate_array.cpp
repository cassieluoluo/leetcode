/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Rotate Array
 *	https://leetcode.com/problems/rotate-array/
 *	Runtime: 25 ms
 */
 
class Solution {
public:
    void reverse(vector<int>& nums, int begin, int end) {
    	while (begin < end) {
    		int temp = nums[begin];
    		nums[begin] = nums[end];
    		nums[end] = temp;
    		begin++; end--;
    	}
    }
    
    void rotate(vector<int>& nums, int k) {
    	k %= nums.size();
    	reverse(nums, 0, nums.size() - 1);
    	reverse(nums, 0, k - 1);
    	reverse(nums, k, nums.size() - 1);
    }
};