/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Gray Code
 *	https://leetcode.com/problems/gray-code/
 *	Runtime: 4 ms
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
    	result.push_back(0);
    	for (int i = 0; i < n; i++) {
    		int msb = 1 << i;
    		for (int j = result.size() - 1; j >= 0; j--) {
    			result.push_back(msb | result[j]);
    		}
    	}
    	return result;
    }
};