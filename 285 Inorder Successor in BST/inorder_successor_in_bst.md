# Inorder Successor in BST
### Difficulty: Medium

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

**Note:** If the given node has no in-order successor in the tree, return `null`.

**Tags:** Tree.

## Explanation

Inorder traversal of a BST yields a sorted array. Therefore the inorder successor of a BST node is the one next to that node in the sorted array.

When we do inorder traversal of a BST, if we travel to the left subtree, the current node is the sucessor. If we travel to the right subtree, the successor is the successor of the current node. This process can be done either recursively or iteratively.

LeetCode Link: [https://leetcode.com/problems/inorder-successor-in-bst/](https://leetcode.com/problems/inorder-successor-in-bst/)

*Author: Xinyu Chen*