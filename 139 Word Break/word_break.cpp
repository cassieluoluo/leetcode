class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == 1 && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = 1;
                }
            }
        }
        return dp.back() == 1;
    }
}; // Author: XC
