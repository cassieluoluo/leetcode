/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Length of Last Word
 *	https://leetcode.com/problems/length-of-last-word/
 *	Runtime: 4 ms
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
    	while (s.rfind(' ') == s.size() - 1) {
    		if (s.size() == 0) return 0;
    		s.resize(s.size() - 1);
    	}
    	int p = s.rfind(' ');
    	if (p == string::npos) return s.size();
    	return s.size() - p - 1;
    }
};