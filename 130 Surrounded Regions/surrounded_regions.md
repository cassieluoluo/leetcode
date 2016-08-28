# Surrounded Regions
### Difficulty: Medium

Given a 2D board containing `'X'` and `'O'` (the letter O), capture all regions surrounded by `'X'`.

A region is captured by flipping all `'O'`s into `'X'`s in that surrounded region.

For example,
```
X X X X
X O O X
X X O X
X O X X
```

After running your function, the board should be:
```
X X X X
X X X X
X X X X
X O X X
```

**Tags:** Breadth-first Search, Union Find.

## Explanation

At first glance, it seems that we need to handle a lot of different situations to determine whether an `O` should be changed into an `X`. However, it is actually quite simple. Imaging the boundary characters are all `X`'s. Which `O`'s should be changed into `X`'s? All of them. Because in this case, everything inside is _surrounded_ by `X`'s. What if the `O` appear on the boundary? Well, this one will not be completely surrounded by `X`'s. So this `O` and any `O`'s that are connected to the one on the boundary are also not completely surrounded. They should not be changed.

Once we have this in mind, the only thing we need to do is to find all the `O`'s that are connected to the boundary. First we find all `O`'s on the boundary, and then do BFS on each of them until we find all the `O`'s that have connection with the boundary. Mark these `O`'s with `Y`. At last, we scan through all the locations and turn `O`'s into `X`'s and turn `Y`'s back into `O`'s.

The time complexity is `O(n)`.

LeetCode Link: [https://leetcode.com/problems/surrounded-regions/](https://leetcode.com/problems/surrounded-regions/)

*Author: Xinyu Chen*
