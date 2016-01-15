public class Solution {	// Author: Xinyu Chen
    public int RemoveElement(int[] nums, int val) {
        int len = nums.Length;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] == val)
            {
                while (len > 0 && nums[len - 1] == val) len--;
                if (i == len) return len;
                nums[i] = nums[len - 1];
                len--;
            }
        }
        return len;
    }
}