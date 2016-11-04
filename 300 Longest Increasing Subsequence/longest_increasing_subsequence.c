int lengthOfLIS(int* nums, int numsSize) {
    int *dp = (int *)malloc(numsSize * sizeof(int));
    int i, j, longest = 0;
    for (i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > longest) longest = dp[i];
    }
    return longest;
} /* Author: XC */
