int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;
    int i = 2, j = 2;
    while (j < numsSize) {
        if (nums[i - 2] != nums[j]) nums[i++] = nums[j];
        j++;
    }
    return i;
} /* Author: XC */
