/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Length of Last Word
 *	https://leetcode.com/problems/length-of-last-word/
 *	Runtime: 118 ms
 */

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    words = s.split(" ");
    for (i = words.length - 1; i >= 0; i--)
        if (words[i].length > 0) return words[i].length;
    return 0;
};