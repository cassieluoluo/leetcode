# Best Time to Buy and Sell Stock
### Difficulty: Medium

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

**Tags:** Array, Dynamic Programming

## Explanation

This problem can be solved by greedy algorithm. We maintain two variables recording the buy price and sell price. Each time we get a new price, we buy at this price if it is lower than the last buy price. And we sell at this price if the sell can make more profit than the current maximum profit. At the end, we will get the maximum profit.

LeetCode Link: [https://leetcode.com/problems/best-time-to-buy-and-sell-stock/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

*Author: Xinyu Chen*