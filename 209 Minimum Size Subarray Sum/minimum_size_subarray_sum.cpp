class Solution {	// Author: Xinyu Chen
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int first = 0, second = 0;
    	int sum = 0, min_len = INT_MAX;
    	while (second < nums.size()) {
    		while (sum < s && second < nums.size()) sum += nums[second++];
    		if (sum < s) break;
    		while (sum >= s && first < second) sum -= nums[first++];
    		min_len = min(min_len, second - first + 1);
    	}
    	if (min_len == INT_MAX) min_len = 0;
    	return min_len;
    }
};