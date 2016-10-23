void moveZeroes(int* nums, int numsSize) {
    if (numsSize < 2) return;
    int slow = 0, fast = 1, temp;
    while (fast < numsSize) {
        if (nums[slow]) fast++;
        else {
            while (nums[fast] == 0) {
                fast++;
                if (fast >= numsSize) return;
            }
            temp = nums[fast];
            nums[fast] = nums[slow];
            nums[slow] = temp;
        }
        slow++;
    }
} /* Author: XC */
