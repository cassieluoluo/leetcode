/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Length of Last Word
 *	https://leetcode.com/problems/length-of-last-word/
 *	Runtime: 1 ms
 */

int lengthOfLastWord(char* s) {
	int t = -1;
	while (s[++t]);
	if (!t) return 0;
	int i = t - 1;
	while (s[i] == ' ' && i > 0) { i--; t--; }
	if (i == 0 && s[0] == ' ') return 0;
	while (s[i] != ' ' && i > 0) i--;
	if (s[i] == ' ') t--;
	return t - i;
}