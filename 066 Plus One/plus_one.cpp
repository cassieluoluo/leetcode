/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Plus One
 *	https://leetcode.com/problems/plus-one/
 *	Runtime: 4 ms
 */
 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	vector<int> res;
    	int carry = 0;
    	int d = digits[digits.size() - 1] + 1;
    	if (d == 10) {
    		carry = 1;
    		res.push_back(0);
    	}
    	else {
    		res.push_back(d);
    	}
    	for (int i = digits.size() - 2; i >= 0; i--) {
    		if (digits[i] == 9 && carry) {
    			res.push_back(0);
    		}
    		else {
    			res.push_back(digits[i] + carry);
    			carry = 0;
    		}
    	}
    	if (carry) res.push_back(1);
    	reverse(res.begin(), res.end());
    	return res;
    }
};