public class Solution
{	// Author: Xinyu Chen
    public IList<IList<int>> Permute(int[] nums)
    {
        var result = new List<IList<int>>();
        DoPermute(new List<int>(nums), 0, result);
        return result;
    }
    public void DoPermute(IList<int> nums, int index, IList<IList<int>> result)
    {
        if (index == nums.Count)
        {
            result.Add(new List<int>(nums));
            return;
        }
        for (int i = index; i < nums.Count; ++i)
        {
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            DoPermute(nums, index + 1, result);
            nums[index] = nums[i];
            nums[i] = temp;
        }
    }
}