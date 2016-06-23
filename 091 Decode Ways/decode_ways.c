int numDecodings(char* s) {
	int len = strlen(s), res;
	if (len == 0 || s[0] == '0') return 0;
	int *ways = (int *)calloc(len + 1, sizeof(int));
	ways[0] = 1;
	ways[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (s[i - 1] != '0') ways[i] = ways[i - 1];
		if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) ways[i] += ways[i - 2];
	}
	res = ways[len];
	free(ways);
	return res;
}
