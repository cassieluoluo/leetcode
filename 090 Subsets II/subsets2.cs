public class Solution {	// Author: Xinyu Chen
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        var result = new List<IList<int>>();
        result.Add(new List<int>());
        Array.Sort(nums);
        int i = 0;
        while (i < nums.Length)
        {
            int dup = 0;
            while (i + dup < nums.Length && nums[i] == nums[i + dup]) dup++;
            int curr = result.Count;
            for (int j = 0; j < curr; j++)
            {
                var row = new List<int>(result[j]);
                for (int k = 0; k < dup; k++)
                {
                    row.Add(nums[i]);
                    var r = new List<int>(row);
                    result.Add(r);
                }
            }
            i += dup;
        }
        return result;
    }
}
