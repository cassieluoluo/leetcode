# First Missing Positive
### Difficulty: Hard

Given an unsorted integer array, find the first missing positive integer.

For example,
Given `[1,2,0]` return `3`,
and `[3,4,-1,1]` return `2`.

Your algorithm should run in *O(n)* time and uses constant space.

**Tags:** Array

## Explanation

Positive integers start from 1. That means if the array does not contain 1, the function should return 1. And if it does contain 1, the return value will be 2 if it does not contain 2. So on and so forth. The ultimate case is that an array of size n contains all integers from 1 to n. Then the result will be `n+1`.

From the above observation, we can see that the result of this problem will be within the range of `[1, n+1]`. Anything that is not in this range can be discarded. For example, if the array contains `[-100, 100, 200, 300]`, the first missing positive integer is 1.

The idea to solve the problem is to put the numbers within the range to their correct positions. Using the given example, `[3,4,-1,1]`. The array has four elements, which means the correct order is `[1,2,3,4]`. Scanning through each number, we run into 3 first and it should be swapped with -1, resulting in `[-1,4,3,1]`. Since -1 is negative, we can move on to the next one, 4. 4 should be swapped with 1. We have `[-1,1,3,4]`. Now at the second place, 1 is in the range and at the wrong position. So we swap it with -1, moving 1 to its correct position. Again we have -1 at the second place and we can move on. Finally we will have `[1,-1,3,4]`. At this point, we can scan through the array to find first position that does not have the corresponding number. In this case, the second position does not have 2. Therefore 2 is the first missing positive integer. On the other hand, if all positions have their corresponding number, we shall return `n+1`.

LeetCode Link: [https://leetcode.com/problems/first-missing-positive/](https://leetcode.com/problems/first-missing-positive/)

*Author: Xinyu Chen*