class Solution {	// Author: Xinyu Chen
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = numeric_limits<int>::max();
        
        sort(nums.begin(), nums.end());
        for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
            auto b = next(a);
            auto c = prev(nums.end());
            while (b < c) {
                int sum = *a + *b + *c;
                int gap = abs(sum - target);
                if (gap < min_gap) {
                    min_gap = gap;
                    result = sum;
                }
                if (sum < target) ++b;
                else --c;
            }
        }
        return result;
    }
};
