public class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length < 2) return false;
        HashSet<Integer> set = new HashSet<Integer>();
        for (int n : nums) {
            if (set.contains(n)) return true;
            set.add(n);
        }
        return false;
    }
} // Author: XC
