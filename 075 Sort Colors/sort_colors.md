# Sort Colors
### Difficulty: Medium

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:**

You are not suppose to use the library's sort function for this problem.

**Follow up:**

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

**Tags:** Array, Two Pointers, Sort.

## Explanation

As mentioned in the problem description, the two-pass solution is essentially a bucket sort. Bucket sort is used when elements of the data belong to a (relatively small) finite set. However, when the finite set contains only three elements, as is in this problem, we can achieve a better solution.

We maintain two indices, one for red from the left, the other for blue from the right. Initially `red = 0` and `blue = nums.size() - 1`. Then we loop through each element using `position` index. When a red is seen, it is swapped with the number (color) at the the red index. After that, both the position index and the red index is advanced by one. When a blue is seen, it is swapped with the number (color) at the blue index. However, we only change the blue index here, subtracting it by one. `position` remains unchanged. Once position meets the blue index, the sorting is completed.

Because we are looping from left to right, we can make sure that all blues (2's) are swapped to the right as we move towards the right. Therefore we can advance `position` index when we run into reds (0's). On the other hand, we cannot advance `position` when we run into blues since that might leave 2's on the left of `position`.

LeetCode Link: [https://leetcode.com/problems/sort-colors/](https://leetcode.com/problems/sort-colors/)

*Author: Xinyu Chen*