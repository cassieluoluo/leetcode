public class Solution {	// Author: Xinyu Chen
    public void SortColors(int[] nums)
    {
        int pos = 0, red = 0, blue = nums.Length - 1;
        while (pos <= blue)
        {
            if (nums[pos] == 0)
            {
                SwapInt(ref nums[pos++], ref nums[red++]);
            }
            else if (nums[pos] == 2)
            {
                SwapInt(ref nums[pos], ref nums[blue--]);
            }
            else pos++;
        }
    }

    private void SwapInt(ref int a, ref int b)
    {
        int c = a;
        a = b;
        b = c;
    }
}