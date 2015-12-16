class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo < hi - 1) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) lo = mid;
            else hi = mid;
        }
        return nums[lo] < nums[hi] ? hi : lo;
    }
};