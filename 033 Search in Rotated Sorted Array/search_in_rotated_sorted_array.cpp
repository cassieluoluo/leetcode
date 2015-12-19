class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if (nums.size() == 0) return -1;
    	int lo = 0, hi = nums.size() - 1, mid = lo + (hi - lo) / 2;
    	while (lo < hi) {
    		mid = lo + (hi - lo) / 2;
    		if (nums[mid] < nums[hi]) hi = mid;
    		else lo = mid + 1;
    	}
    	if (target == nums[mid]) return mid;
    	if (target <= nums[nums.size() - 1]) {
    		hi = nums.size() - 1;
    	}
    	else {
    		hi = lo - 1;
    		lo = 0;
    	}
    	while (lo <= hi) {
    		mid = lo + (hi - lo) / 2;
    		if (nums[mid] == target) return mid;
    		if (nums[mid] < target) lo = mid + 1;
    		else hi = mid - 1;
    	}
    	return -1;
    }
};