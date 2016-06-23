# Path Sum
### Difficulty: Easy

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and `sum = 22`,
<code>
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
</code>
return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

**Tags:** Tree, Depth-first Search

## Explanation
The idea is straight forward. We simply traverse the tree to find the sum of each path, and check to see if there is a match. Note that the termination of a path is when the node has no left nor right child but the node itself is not `null`. A good practice to avoid creating helper functions is to subtract the node values from the sum and compare the final sum with zero. This is equivalent to keeping a separate variable that records the accumulated values.

LeetCode Link: [https://leetcode.com/problems/path-sum/](https://leetcode.com/problems/path-sum/)

*Author: Xinyu Chen*