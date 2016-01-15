# Number of Islands
### Difficulty: Medium

Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

*Example 1:*

<code>
11110
11010
11000
00000
</code>

Answer: 1

*Example 2:*

<code>
11000
11000
00100
00011
</code>

Answer: 3

**Tags:** Depth-first Search, Breadth-first Search, Union Find

## Explanation

There are three different types of algorithm to tackle this problem.

**Depth-first Search**

In the problem description, `1` represents land and `0` represents water. And we use `2` to indicate the location has been visited.

We begin the DFS at all the land localtion. First mark the location as visited. And then recursively search the surrounding four blocks. If it is land, DFS at that location, otherwise (water or visited), just return. 

In the main function, we loop through each land location, once the DFS function returns, we count one island. When all locations are either water or visited, the count is completed.

**Breadth-first Search**

[//]: # (To be done.)

LeetCode Link: [https://leetcode.com/problems/number-of-islands/](https://leetcode.com/problems/number-of-islands/)

*Author: Xinyu Chen*