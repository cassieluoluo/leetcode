void sortColors(int* nums, int numsSize) {
    int red = 0, blue = numsSize - 1, curr = 0;
    while (curr <= blue) {
        if (nums[curr] == 0) {
            nums[curr++] = nums[red];
            nums[red++] = 0;
        } else if (nums[curr] == 2) {
            nums[curr] = nums[blue];
            nums[blue--] = 2;
        } else {
            curr++;
        }
    }
} /* Author: XC */
