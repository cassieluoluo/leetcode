# Validate Binary Search Tree
### Difficulty: Medium

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

**Tags:** Tree, Depth-first Search

## Explanation

The core idea in this problem is how to maintain the minimum and maximum values when recursively checking each subtree. A straight forward way is to use two different recursion functions, one check the left subtree and the other one check the right subtree. A better solution is to pack both minimum and maximum value in the same function. Use `INT_MIN` as the minimum value when checking the left subtree and use the current node value as the maximum value. Same for the right subtree. 

LeetCode Link: [https://leetcode.com/problems/validate-binary-search-tree/](https://leetcode.com/problems/validate-binary-search-tree/)

*Author: Xinyu Chen*