// Author: Xinyu Chen
class Solution {
public:
    int trap(vector<int>& height) {
    	int lo = 0, hi = height.size() - 1;
    	int left = 0, right = 0, total = 0;
    	while (lo <= hi) {
    		if (height[lo] <= height[hi]) {
    			if (height[lo] > left) left = height[lo];
    			else total += left - height[lo];
    			lo++;
    		}
    		else {
    			if (height[hi] > right) right = height[hi];
    			else total += right - height[hi];
    			hi--;
    		}
    	}
    	return total;
    }
};