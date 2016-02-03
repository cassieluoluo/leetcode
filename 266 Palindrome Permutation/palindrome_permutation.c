bool canPermutePalindrome(char* s) {
    int counter[128] = {0};
    while (*s) counter[*s++]++;
    int odd = 0;
    for (int i = 0; i < 128; i++)
        if (counter[i] & 1) odd++;
    return odd < 2;
}	// Author: Xinyu Chen