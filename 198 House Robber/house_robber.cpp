class Solution {	// Author: Xinyu Chen
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        vector<int> result(nums.size() + 1, 0);
        result[0] = 0;
        result[1] = nums[0];
        for (int i = 2; i <= len; i++) {
            result[i] = std::max(result[i - 1], result[i - 2] + nums[i - 1]);
        }
        return result[len];
    }
};
