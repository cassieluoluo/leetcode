/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Reverse Integer
 *	https://leetcode.com/problems/reverse-integer/
 *	Runtime: 12 ms
 */

class Solution {
public:
    int reverse(int x) {
		long long res = 0;
		int input = abs(x);
		while (input > 0) {
			res *= 10;
			res += input % 10;
			input /= 10;
		}
		if (res > INT_MAX) return 0;
		return x >= 0 ? res : -res;
    }
};