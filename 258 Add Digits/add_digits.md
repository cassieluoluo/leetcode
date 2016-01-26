# Add Digits
### Difficulty: Easy

Given a non-negative integer `num`, repeatedly add all its digits until the result has only one digit.

For example:

Given `num = 38`, the process is like: `3 + 8 = 11`, `1 + 1 = 2`. Since `2` has only one digit, return it.

**Tags:** Math

## Explanation

At first glance, we can easily come up with a straight forward solution. Simply add all the digits until the numer is less than 10, as is stated in the problem description. This solution is implmented in the [C# version](add_digits.cs).

However, this problem has a hidden formula. This process is to find so-called **Digital Root** of a number. According to [Wikipedia](https://en.wikipedia.org/wiki/Digital_root),

> The digital root (also repeated digital sum) of a non-negative integer is the (single digit) value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.

And it has a concise congruence formula,

<code>
     / 0, if n == 0
f(n)=| 9, if n % 9 == 0
     \ n % 9, otherwise
</code>

which solves the problem in `O(1)`.

LeetCode Link: [https://leetcode.com/problems/add-digits/](https://leetcode.com/problems/add-digits/)

*Author: Xinyu Chen*
