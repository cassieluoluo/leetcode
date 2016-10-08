char* reverseString(char* s) {
    int len = strlen(s);
    int i = 0, j = len - 1;
    char c;
    while (i < j) {
        c = s[i];
        s[i++] = s[j];
        s[j--] = c;
    }
    return s;
} // Author: XC
