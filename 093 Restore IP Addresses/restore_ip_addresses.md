# Restore IP Addresses
### Difficulty: Medium

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given `"25525511135"`, 

return `["255.255.11.135", "255.255.111.35"]`. (Order does not matter) 

**Tags:** Backtracking, String

## Explanation

This problem can be solved by backtracking. We do a DFS for all possible combinations of numbers and eliminate those are not valid IP addresses.

We use three variables to maintain the current status of the recursion. First one is the current position in the string. Second one is the current segment count. By segment I mean each of the four decimal representation of an IP address. And third one is the partial IP address formed so far.

During each recursion, we pick one, two or three digits from the current position in the input string and *try* to form one segment of the IP address. There are several cases that we need to terminate the search and backtrack to the previous status:

1. The number remaining characters is more than we need to form the rest of the IP address. For example, we have 7 characters remaining while we are in the third segment. We only need at most 6 characters to form the rest part.
2. Any time during the recursion, we have exhausted all the characters in the input string but have not finished the last segment of IP address. 
3. When we add a `0` as the first digit of one segment, since we cannot have leading zeros in a valid IP address.
4. When we add the third digit and the resulting value greater than 255.

Eliminating all these cases can reduce the search space significantly. And finally when we use up all characters in the string and we finished the four segment of a valid IP address, we can add the IP address to the result list.

LeetCode Link: [https://leetcode.com/problems/restore-ip-addresses/](https://leetcode.com/problems/restore-ip-addresses/)

*Author: Xinyu Chen*