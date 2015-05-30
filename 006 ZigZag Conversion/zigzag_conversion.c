/*	
 *	LeetCode Submissions by Xinyu Chen
 *	ZigZag Conversion
 *	https://leetcode.com/problems/zigzag-conversion/
 *	Runtime: 4 ms
 */

char* convert(char* s, int numRows) {
	int len = strlen(s);
	if (len <= numRows || numRows == 1) return s;
	int index = 0, n = numRows * 2 - 2;
	char *ret = (char*)calloc(len + 1, sizeof(char));
	for (int row = 0; row < numRows; row++) {
		if (row == 0 || row == numRows - 1)
			for (int i = 0; i + row < len; i += n) ret[index++] = s[row + i];
		else {
			for (int i = 0; true; i += n) {
				if (i - row >= len) break;
				if (i - row >= 0) ret[index++] = s[i - row];
				if (i + row >= len) break;
				ret[index++] = s[i + row];
			}
		}
	}
	return ret;
}