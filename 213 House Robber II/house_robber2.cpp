class Solution {	// Author: Xinyu Chen
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> b(nums.begin() + 1, nums.end());
        return max(dp(a), dp(b));
    }
    
private:
    int dp(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> count(nums.size() + 1, 0);
        count[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            count[i] = max(count[i - 1], count[i - 2] + nums[i - 1]);
        }
        return count.back();
    }
};
