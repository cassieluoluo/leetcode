int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int f[2];
    f[0] = nums[0];
    f[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for (int i = 2; i < numsSize; ++i) {
        int a = f[(i - 1) % 2];
        int b = f[i % 2] + nums[i];
        f[i % 2] = a > b ? a : b;
    }
    return f[(numsSize - 1) % 2];
} // Author: XC
