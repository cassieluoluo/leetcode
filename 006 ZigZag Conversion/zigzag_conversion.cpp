/*	
 *	LeetCode Submissions by Xinyu Chen
 *	ZigZag Conversion
 *	https://leetcode.com/problems/zigzag-conversion/
 *	Runtime: 16 ms
 */

class Solution {
public:
    string convert(string s, int numRows) {
    	if (s.size() <= numRows || numRows == 1) return s;
    	string ret;
    	int n = numRows * 2 - 2;
    	for (int row = 0; row < numRows; row++) {
    		
    		if (row == 0 || row == numRows - 1) {
    			for (int i = 0; i + row < s.size(); i += n) {
    				ret.push_back(s[row + i]);
    			}
    		}
    		else {
    			int i = -n;
    			while (true) {
    				i += n;
    				if (i - row >= (int)s.size()) break;
    				if (i - row >= 0) ret.push_back(s[i - row]);
    				if (i + row >= s.size()) break;
    				ret.push_back(s[i + row]);
    			}
    		}
    	}
    	return ret;
    }
};