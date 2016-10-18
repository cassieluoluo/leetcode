public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        if (nums.Length < 2) return false;
        HashSet<int> set = new HashSet<int>();
        foreach (var n in nums)
        {
            if (set.Contains(n)) return true;
            set.Add(n);
        }
        return false;
    }
} // Author: XC
