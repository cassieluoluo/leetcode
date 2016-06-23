bool canJump(int* nums, int numsSize) {
    int last = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > last) return false;
        last = nums[i] + i > last ? nums[i] + i : last;
    }
    return true;
}
