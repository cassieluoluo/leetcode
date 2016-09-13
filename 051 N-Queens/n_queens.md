# N-Queens
### Difficulty: Medium

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
```
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```

**Tags:** Backtracking.

## Explanation

This is a typical problem derived from the eight-queen problem. The standard chessboard is an 8-by-8 grid and therefore at most eight queens can stay on the board such that no two queens can attack each other. Here's why: since queens are able to attack anything on the same row or same column, at most one queen can be placed on each row (column).  

Now, we can apply the same solution to the N-queens problem. The solution space is a complete n-nary tree, where each tree level represent one row on the chessboard. Brutal force search of the whole tree is not realistic. Using the idea of backtracking, we can prune many branches that conflicts with the chess rules.
*To be continued...*

LeetCode Link: [https://leetcode.com/problems/n-queens/](https://leetcode.com/problems/n-queens/)

*Author: Xinyu Chen*
