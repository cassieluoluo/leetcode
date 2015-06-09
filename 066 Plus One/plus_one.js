/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Plus One
 *	https://leetcode.com/problems/plus-one/
 *	Runtime: 139 ms
 */
 
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var res = [];
    var carry = 0;
    if (digits[digits.length - 1] == 9) {
        res.push(0);
        carry = 1;
    } else {
        res.push(digits[digits.length - 1] + 1);
    }
    for (var i = digits.length - 2; i >=0; i--) {
        if (digits[i] == 9 && carry == 1) {
            res.push(0);
        } else {
            res.push(digits[i] + carry);
            carry = 0;
        }
    }
    if (carry == 1) {
        res.push(1);
    }
    res.reverse();
    return res;
};
