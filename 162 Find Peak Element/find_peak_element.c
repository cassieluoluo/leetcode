int findPeakElement(int* nums, int numsSize) {
    int lo = 0, hi = numsSize - 1;
    int mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] < nums[mid + 1]) lo = mid;
        else hi = mid;
    }
    return nums[lo] > nums[hi] ? lo : hi;
}   // Author: XC