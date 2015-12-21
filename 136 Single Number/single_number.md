# Single Number
### Difficulty: Medium

Given an array of integers, every element appears twice except for one. Find that single one.

**Tags:** Hash Table, Bit Manipulation

## Explanation

Although hash table appears in the tags, the best solution is to use bit manipulation. We utilize the property of eXclusive OR (XOR) operation. XORing two same numbers results in zero. And this property is transitive. That means, a sequence of numbers XORing each other will cancel out all the numbers that appear even numbers of times and leaving the number appearing odd numbers of times. Since we only have one number appearing odd times, that is the number we want to find.

LeetCode Link: [https://leetcode.com/problems/single-number/](https://leetcode.com/problems/single-number/)

*Author: Xinyu Chen*