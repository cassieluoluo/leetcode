class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
    	int p = 0, q = 0;
    	for (size_t i = nums.size() - 1; i > 0; i--) {
    		if (nums[i] > nums[i - 1]) {
    			p = i - 1;
    			break;
    		}
    	}
    	for (size_t i = nums.size() - 1; i > p; i--) {
    		if (nums[i] > nums[p]) {
    			q = i;
    			break;
    		}
    	}
    	swap(nums[p], nums[q]);
    	if (q == 0) p = -1;
    	auto it = nums.begin() + p + 1;
    	reverse(it, nums.end());
    }
};