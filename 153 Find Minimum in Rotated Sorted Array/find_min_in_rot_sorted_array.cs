public class Solution {
    public int FindMin(int[] nums) {
        int lo = 0, hi = nums.Length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[lo]) hi = mid;
            else if (nums[mid] > nums[hi]) lo = mid + 1;
            else break;
        }
        return nums[lo];
    }
} // Author: XC