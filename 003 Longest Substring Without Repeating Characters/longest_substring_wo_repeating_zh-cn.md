# Longest Substring Without Repeating Characters
### Difficulty: Medium

Given a string, find the length of the longest substring without repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

**Tags:** Hash Table, Two Pointers, String

## Explanation

这道题是典型的两个指针类型的问题。用快慢指针划定字串的范围。快指针在前，依次遍历字符，并加入到一个集合中。若遇到集合中已经存在的元素，则说明字串从当前位置出现了重复。此时更新最大长度，并将慢指针所指向的字符从集合中删除，同时向前移动慢指针。快指针到达字符串结尾之际，即可跳出循环，返回结果。

该算法的时间复杂度是`O(n)`，空间复杂度是`O(1)`。

LeetCode Link: [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

*Author: Xinyu Chen*
