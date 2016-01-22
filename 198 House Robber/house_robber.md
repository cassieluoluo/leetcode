# House Robber
### Difficulty: Easy

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.

**Tags:** Dynamic Programming

## Explanation

The most important step to solve a dynamic programming problem is to find the transfer function. Assume we are at the door of the *n*th house. Now we have two choices, depending on the previous situation: either we have robbed the previous house right before this one, or we haven't. In the former case, we cannot rob the current one. The total amount remain the same as the when we were at the previous hosue. In the latter case, we can rob the current one and the total amount is the amount in the current hosue plus the amount we had when we robbed the house before the previous one. Therefore we have the following

`f(n)=max(f(n-1), f(n-2)+a(n))`

Note that `a(n)` here is the amount of money stashed in the *n*th house where `n` starts from 1. However, the index of array `nums` starts from 0. 

LeetCode Link: [https://leetcode.com/problems/house-robber/](https://leetcode.com/problems/house-robber/)

*Author: Xinyu Chen*
