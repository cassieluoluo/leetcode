/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Plus One
 *	https://leetcode.com/problems/plus-one/
 *	Runtime: 0 ms
 */
 
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int* results = (int*)calloc(digitsSize + 1, sizeof(int));
	*returnSize = digitsSize;
	int index = digitsSize - 1;
	int carry = 0;
	if (digits[index] == 9) {
		results[index + 1] = 0;
		carry = 1;
	}
	else results[index + 1] = digits[index] + 1;
	while (--index >= 0) {
		if (digits[index] == 9 && carry) {
			results[index + 1] = 0;
			carry = 1;
		}
		else {
			results[index + 1] = digits[index] + carry;
			carry = 0;
		}
	}
	if (carry) {
		results[0] = 1;
		(*returnSize)++;
		return results;
	}
	else return results + 1;
}
