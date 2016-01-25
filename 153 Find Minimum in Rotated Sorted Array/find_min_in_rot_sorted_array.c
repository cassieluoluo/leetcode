int findMin(int* nums, int numsSize) {
    int lo = 0, hi = numsSize - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[lo] > nums[mid]) hi = mid;
        else if (nums[hi] < nums[mid]) lo = mid + 1;
        else break;
    }
    return nums[lo];
} // Author: Xinyu Chen
