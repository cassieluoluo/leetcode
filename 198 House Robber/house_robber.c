int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int *count = (int *)calloc(numsSize + 1, sizeof(int));
    count[0] = 0;
    count[1] = nums[0];
    for (int i = 2; i <= numsSize; ++i) {
        int a = count[i - 1];
        int b = count[i - 2] + nums[i - 1];
        count[i] = a > b ? a : b;
    }
    return count[numsSize];
}	// Author: Xinyu Chen
