/*
 *	LeetCode Submissions by Xinyu Chen
 *	Reverse Integer
 *	https://leetcode.com/problems/reverse-integer/
 *	Runtime: 172 ms
 */

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var res = 0;
    data = Math.abs(x);
    while (data > 0) {
        res *= 10;
        rem = data % 10;
        res += rem;
        data -= rem;
        data = Math.floor(data / 10);
    }
    if (res > Math.pow(2, 31) - 1) return 0;
    return x >= 0 ? res : -res;
};