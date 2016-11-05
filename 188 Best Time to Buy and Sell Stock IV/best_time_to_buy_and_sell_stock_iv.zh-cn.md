# Best time to buy and sell stock
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

## 分类
* 动态规划

## 解法
由于是动态规划问题，首先是要找出状态关系式，假设在前i个价格中有j次交易所能达到的最大收益为s[i][j], 那么在前i+1个价格中有j次交易的最大收益i[i+1][j]就应该是以下两个情况中最大的那一个

    1.  s[i][j]
    2.  s[i-1][j-1] + (prices[i+1] - prices[i])

由此可以写出一个双循环的解

* 时间复杂度：`O(k*n)`
* 空间复杂度：`O(k*n)`

## 边界条件
无

## 备注
无

## 参考文献
https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java
