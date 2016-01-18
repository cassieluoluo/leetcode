# Palindrome Linked List
### Difficulty: Easy

Given a singly linked list, determine if it is a palindrome.

**Follow up:**

Could you do it in O(n) time and O(1) space?

**Tags:** Linked List, Two Pointers

## Explanation

It is easy to determine whehther an array is a palindrome since array has O(1) random access. However, for a singly linked list, we cannot go back once we move forward. On the other hand, we need to find the mid point of the linked list in order to check for a palindrome.

Fortunately, we can solve the two problems at the same time, using two pointers. The fast pointer travels twice as fast as the slow one. Once the fast pointer reaches the end of the linked list, the slow one will point to the middle element. Meanwhile, as the slow pointer moves forward, it reverses the linked list so that we can travel back later to check element values on both sides.

Note that the slow pointer could end up at two different positions depending on whether the linked list contains even or odd number of elements. It is easy to distinguish the two cases by looking at the end position of the fast pointer. If is `nullptr`, the linked list has even number of elements. Therefore when we begin to check values from the middle to both sides, the right half starts at the position where the slow pointer is pointing to. Otherwise, we have odd number of elements in the linked list, the middle one does not need to be checked. The right half starts from the posision next to the slow pointer.

LeetCode Link: [https://leetcode.com/problems/palindrome-linked-list/](https://leetcode.com/problems/palindrome-linked-list/)

*Author: Xinyu Chen*