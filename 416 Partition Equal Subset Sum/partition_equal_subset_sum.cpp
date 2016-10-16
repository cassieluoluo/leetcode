class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, curr = 0;
        for (auto n : nums) sum += n;
        int target = sum / 2;
        if (sum % 2 == 1) return false;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (auto n : nums) {
            if (n > target) return false;
            for (int i = curr; i >= 0; i--) {
                if (dp[i] && i + n <= target) {
                    dp[i + n] = 1;
                    curr = max(curr, i + n);
                    if (curr == target) return true;
                }
            }
        }
        return dp[target];
    }
}; // Author: XC
