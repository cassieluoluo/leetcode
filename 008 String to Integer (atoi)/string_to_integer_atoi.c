/*	
 *	LeetCode Submissions by Xinyu Chen
 *	String to Integer (atoi)
 *	https://leetcode.com/problems/string-to-integer-atoi/
 *	Runtime: 4 ms
 */

int myAtoi(char* str) {
	int index = 0;
	while (str[index] == ' '
		|| str[index] == '\t'
		|| str[index] == '\r'
		|| str[index] == '\n')
		index++;
	bool negative = false;
	if (str[index] == '-') {
		negative = true;
		index++;
	}
	else if (str[index] == '+') {
		index++;
	}
	else if (str[index] < '0' || str[index] > '9') return 0;

	char *buffer = (char*)calloc(strlen(str) - index, sizeof(char));
	int buffer_index = 0;
	while (str[index] >= '0' && str[index] <= '9')
		buffer[buffer_index++] = str[index++];
	long long result = 0;
	for (int i = 0; i < buffer_index; i++) {
		result *= 10;
		result += buffer[i] - '0';
		if (!negative && result > INT_MAX) return INT_MAX;
		else if (negative && -result < INT_MIN) return INT_MIN;
	}
	return negative ? -result : result;
}