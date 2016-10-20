int firstUniqChar(char* s) {
    int len = strlen(s);
    int chs[256] = {0}, pos[256], i, index = len;
	for (i = 0; i < 256; i++) pos[i] = len;
    for (i = 0; i < len; i++) {
        chs[s[i]]++;
        if (pos[s[i]] == len) pos[s[i]] = i;
    }
    for (i = 0; i < 256; i++) {
        if (chs[i] == 1 && pos[i] < index) index = pos[i];
    }
    return index == len ? -1 : index;
} /* Author: XC */
