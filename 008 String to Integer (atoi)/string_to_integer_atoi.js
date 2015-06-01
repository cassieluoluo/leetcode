/*	
 *	LeetCode Submissions by Xinyu Chen
 *	String to Integer (atoi)
 *	https://leetcode.com/problems/string-to-integer-atoi/
 *	Runtime: 208 ms
 */
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    if (str.length === 0) return 0;
    var index = 0;
    while (str.charAt(index) == ' '
        || str.charAt(index) == '\t'
        || str.charAt(index) == '\r'
        || str.charAt(index) == '\n')
        index++;
    var negative = false;
    if (str.charAt(index) == '-') {
        negative = true;
        index++;
    } else if (str.charAt(index) == '+') index++;
    else if (str.charAt(index) < '0' || str.charAt(index) > '9') return 0;
    var buffer = new Array(str.length - index);
    var cnt = 0;
    while (str.charAt(index) >= '0' && str.charAt(index) <= '9') {
        buffer[cnt++] = str.charAt(index++);
    }
    var res = 0;
    for (var i = 0; i < cnt; i++) {
        res *= 10;
        res += buffer[i].charCodeAt(0) - '0'.charCodeAt(0);
        if (negative && res > 2147483648) return -2147483648;
        if (!negative && res > 2147483647) return 2147483647;
    }
    return negative ? -res : res;
};
