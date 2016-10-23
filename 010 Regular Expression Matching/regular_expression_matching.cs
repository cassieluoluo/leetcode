public class Solution {
    public bool IsMatch(string s, string p) {
        int ls = s.Length, lp = p.Length;
        bool[,] dp = new bool[ls + 1, lp + 1];
        dp[0, 0] = true;
        for (int i = 0; i <= ls; i++) {
            for (int j = 1; j <= lp; j++) {
                if (p[j - 1] != '*')
                    dp[i, j] = i > 0 && dp[i - 1, j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                else
                    dp[i, j] = dp[i, j - 2] || (i > 0 && dp[i - 1, j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
        return dp[ls, lp];
    }
} // Author: XC
