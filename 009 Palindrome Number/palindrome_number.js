/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Palindrome Number 
 *	https://leetcode.com/problems/palindrome-number/
 *	Runtime: 588 ms
 */

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x == 0) return true;
    if (x < 0) return false;
    len = Math.ceil(Math.log(x) / Math.log(10));
    base = Math.floor(Math.pow(10, len - 1));
    for (i = 0; i < len / 2; i++) {
        if (x % 10 != Math.floor(x / base)) return false;
        x %= base;
        x = Math.floor(x / 10);
        base = Math.floor(base / 100);
    }
    return true;
};