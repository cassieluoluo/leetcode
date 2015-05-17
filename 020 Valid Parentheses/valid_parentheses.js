/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Valid Parentheses
 *	https://leetcode.com/problems/valid-parentheses/
 *	Runtime: 123 ms
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var st = [];
    for (i = 0; i < s.length; i++) {
        if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') st.push(s.charAt(i));
        else if (st.length === 0) return false;
        else {
            switch(s.charAt(i)) {
                case ')':
                    if (st.pop() != '(') return false;
                    break;
                case '}':
                    if (st.pop() != '{') return false;
                    break;
                case ']':
                    if (st.pop() != '[') return false;
                    break;
            }
        }
    }
    if (st.length === 0) return true;
    return false;
};