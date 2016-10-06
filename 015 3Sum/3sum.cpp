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
}; // Author: XC

// Another solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
		int len = nums.size();
        if (len < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
			int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> r{ nums[i], nums[j], nums[k] };
                    res.push_back(r);
					j++;
					k--;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
}; // Author: XC
