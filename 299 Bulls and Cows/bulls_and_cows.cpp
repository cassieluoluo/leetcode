class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int s_digits[10] = {0};
        int g_digits[10] = {0};
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            s_digits[secret[i] - '0']++;
            g_digits[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            cows += min(s_digits[i], g_digits[i]);
        }
        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};