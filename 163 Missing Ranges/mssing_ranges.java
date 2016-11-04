public class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> missRanges = new ArrayList<>();
        long low = (long) lower;
        long up = (long) upper;
        for (int i = 0; i < nums.length && nums[i] <= upper;i++) {
            long num = (long) nums[i];
            if (low > num) continue;
            if(low < num){
                if (num == low + 1) missRanges.add(String.valueOf(low));
                else missRanges.add(low + "->" + (num - 1));
            } 
            low = num + 1;
        }
        if (low < up) missRanges.add(low + "->" + up);
        if (low == up) missRanges.add(String.valueOf(low));
        return missRanges;
    }
} // Author: Cassie
