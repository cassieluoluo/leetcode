public class Solution {
    private IList<IList<int>> result;
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        Array.Sort(candidates);
        IList<int> entry = new List<int>();
        result = new List<IList<int>>();
        helper(candidates, entry, target, 0, 0);
        return result;
        
    }
    
    private void helper(int[] candidates, IList<int> entry, int target, int sum, int curr) {
        if (sum > target) return;
        if (sum == target) {
            result.Add(new List<int>(entry));
            return;
        }
        for (int i = curr; i < candidates.Length; i++) {
            entry.Add(candidates[i]);
            helper(candidates, entry, target, sum + candidates[i], i);
            entry.RemoveAt(entry.Count - 1);
        }
    }
} // Author: XC
