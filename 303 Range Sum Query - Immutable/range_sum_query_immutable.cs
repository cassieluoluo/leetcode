public class NumArray	// Author: Xinyu Chen
{
    private int[] data;
    
    public NumArray(int[] nums)
    {
        if (nums.Length == 0) return;
        data = new int[nums.Length];
        data[0] = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            data[i] = data[i - 1] + nums[i];
        }
    }
    
    public int SumRange(int i, int j)
    {
        if (i == 0) return data[j];
        return data[j] - data[i - 1];
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.SumRange(0, 1);
// numArray.SumRange(1, 2);
