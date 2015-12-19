// Author : Xinyu Chen
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> valid{1};
        for (auto n : nums)
            if (n > 0) valid.push_back(n);
        valid.push_back(1);
        int len = valid.size();
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for (int range = 1; range < len; range++) {
            for (int left = 1; left < len - range; left++) {
                int right = left + range - 1;
                int most = 0;
                for (int i = left; i <= right; i++) {
                    int total = dp[left][i - 1] + dp[i + 1][right]
                        + valid[left - 1] * valid[i] * valid[right + 1];
                    most = max(most, total);
                }
                dp[left][right] = most;
            }
        }
        return dp[1][len - 2];
    }
};