public class Solution {
    public void MoveZeroes(int[] nums) {
        int pos = 0;
        foreach (var n in nums) {
            if (n != 0) nums[pos++] = n;
        }
        while (pos < nums.Length) {
            nums[pos++] = 0;
        }
    }
} // Author: XC
