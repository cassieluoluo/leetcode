/*	
 *	LeetCode Submissions by Xinyu Chen
 *	3Sum
 *	https://leetcode.com/problems/3sum/
 *	Runtime: 60 ms
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        
        const int target = 0;
        int lo = 0;
        int hi = nums.size();
        for (auto i = nums.begin(); i < nums.end() - 2; ++i) {
            auto j = i + 1;
            if (i > nums.begin() && *i == *(i - 1)) continue;
            auto k = nums.end() - 1;
            while (j < k) {
                if (*i + *j + *k < target) {
                    ++j;
                    while (*j == *(j - 1) && j < k) ++j;
                }
                else if (*i + *j + *k > target) {
                    --k;
                    while (*k == *(k + 1) && j < k) --k;
                }
                else {
                    vector<int> res{*i, *j, *k};
                    result.push_back(res);
                    ++j;
                    --k;
                    while (*j == *(j - 1) && j < k) ++j;
                }
            }
        }
        return result;
    }
};