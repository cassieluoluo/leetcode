void reverseString(char *s, int lo, int hi) {
    char temp;
    while (lo < hi) {
        temp = s[lo];
        s[lo] = s[hi];
        s[hi] = temp;
        lo++;
        hi--;
    }
}

void reverseWords(char *s) {
    int start = 0, end = 0;
    while (s[end] != '\0') {
        while (s[end] != ' ' && s[end] != '\0') end++;
        reverseString(s, start, end - 1);
        if (s[end] == '\0') break;
        start = end + 1;
        end = start;
    }
    reverseString(s, 0, end - 1);
}