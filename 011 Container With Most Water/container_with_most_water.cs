public class Solution {	// Author: Xinyu Chen
    public int MaxArea(int[] height) {
        int volume = 0;
        int lo = 0, hi = height.Length - 1;
        while (lo < hi) {
            int h = Math.Min(height[lo], height[hi]);
            volume = Math.Max(volume, (hi - lo) * h);
            while (height[lo] <= h && lo < hi) lo++;
            while (height[hi] <= h && lo < hi) hi--;
        }
        return volume;
    }
}