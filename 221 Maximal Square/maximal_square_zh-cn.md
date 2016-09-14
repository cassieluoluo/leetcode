# Maximal Square
### Difficulty: Medium

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:
```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```
Return 4.

**Tags:** Dynamic Programming.

## Explanation

这道题用动态规划来解决。考虑以某个点作为正方形的右下角，把从这点向左上角扩展可以构成的最大正方形的边长作为状态。如果当前考虑的点本身是0，那么这一点的状态就是0。如果这个点是1，那么它的状态和它左上角的，上面的，以及左边的三个点的状态有关。以当前点作为右下角能够向左上角扩展的最大正方形的边长，是它左上角，左边，上面这三个位置的状态的最小值加一，因为它本身也是1，可以作为边长的一部分。

常规的解法用一个二维数组来记录每个点的状态，其空间复杂度为`O(n^2)`。如上文所述，每个点的状态实际上只与之前的三个状态有关，所以可以使用滚动数组的方式来优化空间复杂度到`O(n)`。具体方法参见C++代码。

LeetCode Link: [Maximal Square](https://leetcode.com/problems/maximal-square/)

*Author: Xinyu Chen*
