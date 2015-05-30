/*	
 *	LeetCode Submissions by Xinyu Chen
 *	ZigZag Conversion
 *	https://leetcode.com/problems/zigzag-conversion/
 *	Runtime: 232 ms
 */

/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (s.length <= numRows || numRows == 1) return s;
    ret = new Array(s.length);
    var n = numRows * 2 - 2;
    var index = 0;
    for (var row = 0; row < numRows; row++) {
        if (row === 0 || row == numRows - 1) {
            for (var i = 0; i + row < s.length; i += n) {
                ret[index++] = s.charAt(row + i);
            }
        } else {
            i = -n;
            while (true) {
                i += n;
                if (i - row >= s.length) break;
                if (i - row >= 0) ret[index++] = s.charAt(i - row);
                if (i + row >= s.length) break;
                ret[index++] = s.charAt(i + row);
            }
        }
    }
    return ret.join('');
};