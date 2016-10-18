int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int i = 0, j = 1;
    while (j < numsSize) {
        while (j < numsSize && nums[j] == nums[i]) j++;
        if (j == numsSize) break;
        nums[++i] = nums[j++];
    }
    return i + 1;
} /* Author: XC */
