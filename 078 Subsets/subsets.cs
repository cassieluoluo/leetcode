public class Solution {	// Author: Xinyu Chen
    public IList<IList<int>> Subsets(int[] nums) {
        Array.Sort(nums);
        int numElements = nums.Length;
        int numSets = 1 << numElements;
        var result = new List<IList<int>>(numSets);
        for (int i = 0; i < numSets; i++)
        {
            var set = new List<int>();
            for (int j = 0; j < numElements; j++)
            {
                if ((i & (1 << j)) != 0)
                {
                    set.Add(nums[j]);
                }
            }
            result.Add(set);
        }
        return result;
    }
}
