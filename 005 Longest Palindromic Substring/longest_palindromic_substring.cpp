/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Longest Palindromic Substring
 *	https://leetcode.com/problems/longest-palindromic-substring/
 *	Runtime: 72 ms
 */

class Solution {
public:
    int start, mlen;
    string longestPalindrome(string s) {
        start = 0;
        mlen = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            extend(s, i, i);
            extend(s, i, i + 1);
        }
        return s.substr(start, mlen);
    }
    void extend(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--; right++;
        }
        left++; right--;
        if (mlen < right - left + 1) {
            mlen = right - left + 1;
            start = left;
        }
    }
};