# First Bad Version
### Difficulty: Easy

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which will return whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Tags:** Binary Search

## Explanation

The straight forward idea is to scan from the first version until we run into the bad version. This is an `O(n)` algorithm. Sure we can do better than that. To find out the first bad version, we don't have to check every single version. This is because bad versions do not appear randomly. All the versions following a bad version are all bad. This reminds us of binary search, which gives `log(n)` time complexity. We have two pointers pointing to the begin and end of the version numbers. First we check the middle one. If that one is bad, the first bad version will be somewhere in the left part. Otherwise, the bad version should be in the right part. So we adjust the left and right pointer accordingly. This will lead us to the result when the two pointers meets each other (actually adjacent to each other). At that moment, the right pointer will point to the first bad version.

There is one corner case we need to pay attention to. When first bad version happens at the beginning, i.e. the first versiion is a bad one, the algorithm described above will not work correctly as we assume the left pointer always points to a good version. This case should be checked and excluded at the beginning of the algorithm.

LeetCode Link: [https://leetcode.com/problems/first-bad-version/](https://leetcode.com/problems/first-bad-version/)

*Author: Xinyu Chen*
