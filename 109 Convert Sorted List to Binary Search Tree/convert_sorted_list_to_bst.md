# Convert Sorted List to Binary Search Tree
### Difficulty: Medium

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

**Tags:** Depth-first Search, Linked List

## Explanation

To construct a height-balanced binary search tree, we need to use the median value as the root. And then recursively construct its left and right subtree.

Since the list is ordered, the median is the value in the middle. However, linked list does not have random access. To get to the middle point, we use two pointers: slow and fast. Fast pointer travels twice as fast as the slow one. This is a typical technique in processing linked list.

After creating the root node of the tree, we can construct its left and right subtree by recursively call the function using the previous head and the node after the middle point as parameters.

There are two details we need to pay attention to.

First, in a typical two pointer traversal, the slow pointer stops at the node to the right of the middle position when there are even number of nodes in the linked list. This is not the desired result as it will fail to balance the tree. We would like to have the slow pointer stop at one place before the middle position. A simple solution to this problem is to make the fast pointer travel one step in advance.

Second, do not forget to disconnect the linked list from the middle before we construct the left subtree. Otherwise the left subtree will contain values larger than the median. The previous paragraph prepares the pointer for this operation.

LeetCode Link: [https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

*Author: Xinyu Chen*
