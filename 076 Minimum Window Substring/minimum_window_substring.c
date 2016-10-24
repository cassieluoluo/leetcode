char* minWindow(char* s, char* t) {
    int hash[256] = { 0 };
    int len_s = strlen(s);
    int len_t = strlen(t);
	int start = 0, end, count = 0, len = INT_MAX;
	char *res = (char *)calloc(len_s + 1, sizeof(char));
	for (end = 0; end < len_t; end++) hash[t[end]]++;
    for (end = 0; end < len_s; end++) {
        hash[s[end]]--;
        if (hash[s[end]] >= 0) ++count;
        while (count == len_t) {
            if (end - start + 1 < len) {
                len = end - start + 1;
                strncpy(res, s + start, len);
                res[len] = '\0';
            }
            hash[s[start]]++;
            if (hash[s[start]] > 0) --count;
            start++;
        }
    }
    return res;
} /* Author: XC */
