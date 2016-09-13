# House Robber
### Difficulty: Easy

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.

**Tags:** Dynamic Programming

## Explanation

本题是典型的动态规划问题。对于房子`i`而言，在这个位置能抢到的钱数取决于是否抢这幢房子。如果前一幢房子`i-1`已经抢过，那么这幢房子就不能抢了，因而最大钱数和前一幢房子`i-1`处的最大钱数相等。如果没有抢前一幢房子，则可以抢当前位置的房子。此时能抢到的最大钱数是该房子里的钱数`nums[i]`与隔开一幢房子`i-2`的位置能抢到的钱数之和。然后再比较两种不同情况的钱数，取较多的那个作为当前能抢到的最大钱数。递推公式如下

```f(n)=max(f(n-1), f(n-2)+a(n))```

动态规划问题如果用递归实现通常效率较低，数据量大的时候很容易发生栈溢出。所以一般都用迭代方法来实现。用数组来记录已有的数据，从而进行后续运算。参见C++版本。然而，这种做法的空间复杂度是`O(n)`的，不是最优解。从递推表达式可以看出，每个状态的值只与它前两个状态的值有关，所以我们不必存储所有的历史数据，只需缓存过去两个状态的值即可。使用模运算可以交替地在两个缓存变量里存取数值，参见C语言版本。

LeetCode Link: [House Robber](https://leetcode.com/problems/house-robber/)

*Author: Xinyu Chen*
