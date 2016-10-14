/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *res = (int *)malloc(numsSize * sizeof(int));
    res[0] = 1;
    int i, p = 1;
    for (i = 1; i < numsSize; i++) {
        p *= nums[i - 1];
		res[i] = p;
    }
	p = 1;
    for (i = numsSize - 2; i >= 0; i--) {
        p *= nums[i + 1];
        res[i] *= p;
    }
    *returnSize = numsSize;
    return res;
} // Author: XC
