/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    *returnSize = 1 << numsSize;
    int i, j, c, *r;
    int **res = (int **)malloc(*returnSize * sizeof(int *));
    *columnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        r = (int *)malloc(numsSize * sizeof(int));
        c = 0;
        for (j = 0; j < numsSize; j++) {
            if ((i >> j) & 1) r[c++] = nums[j];
        }
        (*columnSizes)[i] = c;
        res[i] = r;
    }
    return res;
} /* Author: XC */
