/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(int *nums, int numsSize, int pos, int **result, int *index) {
    if (pos == numsSize) {
        int *row = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) row[i] = nums[i];
        result[(*index)++] = row;
        return;
    }
    for (int i = pos; i < numsSize; i++) {
        int temp = nums[i];
        nums[i] = nums[pos];
        nums[pos] = temp;
        dfs(nums, numsSize, pos + 1, result, index);
        nums[pos] = nums[i];
        nums[i] = temp;
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
	*returnSize = 1;
	for (int i = 2; i <= numsSize; i++) *returnSize *= i;
	int **result = (int **)malloc(*returnSize * sizeof(int *));
	int index = 0;
	dfs(nums, numsSize, 0, result, &index);
	return result;
} /* Author: Xinyu Chen */
