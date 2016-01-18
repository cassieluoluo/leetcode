# Coin Change
### Difficulty: Medium

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

**Example 1:**
coins = `[1, 2, 5]`, amount = `11`
return `3` (11 = 5 + 5 + 1)

**Example 2:**
coins = `[2]`, amount = `3`
return `-1`.

**Note:**
You may assume that you have an infinite number of each kind of coin.

**Tags:** Dynamic Programming

## Explanation

*This article is a little bit wordy. I will clean it up later.*

This problem is a typical dynamic programming problem. Both recursion and iteration can solve this problem. However, we prefer iteration to recursion since it is usually faster.

The iterative solution solves the problem in a bottom-up manner. Let's see the first example in the problem description. First we consider, what if the amount is only one? Obviously we can use one `1` to make up the amount. That is easy. Then how about amount `2`? It is sitll easy to see that either one `2` or two `1`s make up the amount. And we choose one `2` as the solution since we are looking for the minimum value. This process won't go too far. Suppose we are in the middle of this process. Now how about amount `6`? We cannot continue our intuitive guess as the previous ones.

We are wise enough to record all the results from amount `1` to `5`. For amount `6`, we first try to use coin `1`. And we need `5`. Now the problem becomes: how can we choose a minimum number of coins to make up amount `5`? We have already solve this problem before and recorded its solution. Therefore in this case, the number of coins needed is simply one plus the solution for amount `5`.

Then we try to use coin `2`. Similiar to the method above, we lookup the table of previous solutions and find the number of coins for amount `4`. And the total number is one plus solution for amount `4`. If this number is smaller than the one produced in the previous step, we know that this will be a better solution.

Once we have tried all the coins, we will find the minimum number of coins for the current amount. Record it and compute the next one.

LeetCode Link: [https://leetcode.com/problems/coin-change/](https://leetcode.com/problems/coin-change/)

*Author: Xinyu Chen*