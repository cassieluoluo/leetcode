/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Valid Parentheses
 *	https://leetcode.com/problems/valid-parentheses/
 *	Runtime: 1 ms
 */

bool isValid(char* s) {
    char *st = (char*)malloc(1024 * sizeof(char));
	int index = 0;
	while (*s) {
		if (*s == '(' || *s == '{' || *s == '[') {
			st[index] = *s;
			index++;
		}
		else if (index == 0) return 0;
		else {
			switch (*s)
			{
			case ')':
				if (st[--index] != '(') return 0;
				break;
			case '}':
				if (st[--index] != '{') return 0;
				break;
			case ']':
				if (st[--index] != '[') return 0;
				break;
			}
		}
		s++;
	}
	return !index;
}