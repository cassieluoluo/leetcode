public class Solution {
    public bool WordBreak(string s, ISet<string> wordDict) {
        bool[] dp = new bool[s.Length + 1];
        dp[0] = true;
        for (int i = 1; i <= s.Length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.Contains(s.Substring(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.Length];
    }
} // Author: XC
