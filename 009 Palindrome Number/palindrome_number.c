/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Palindrome Number 
 *	https://leetcode.com/problems/palindrome-number/
 *	Runtime: 52 ms
 */
 
bool isPalindrome(long long x) {
	if (x == 0) return true;
	if (x < 0) return false;
	int len = (int)ceil(log10(x + 1));
	long long base = 1;
	for (int i = 0; i < len - 1; i++) base *= 10;
	for (int i = 0; i < len / 2; i++) {
		if (x % 10 != x / base) return false;
		x = x % base;
		x /= 10;
		base /= 100;
	}
	return true;
}