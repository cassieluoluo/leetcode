class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
    	int len = nums.size();
    	if (len < 4) return result;
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < len - 3; i++) {
    	    for (int j = i + 1; j < len - 2; j++) {
    	        int two = target - nums[i] - nums[j];
    	        int p = j + 1, q = len - 1;
    	        while (p < q) {
    	            int sum = nums[p] + nums[q];
    	            if (sum < two) p++;
    	            else if (sum > two) q--;
    	            else {
    	                vector<int> quad{nums[i], nums[j], nums[p], nums[q]};
    	                result.push_back(quad);
    	                p++; q--;
    	                while (p < q && nums[q] == nums[q + 1]) q--;
    	                while (p < q && nums[p] == nums[p - 1]) p++;
    	            }
    	        }
    	        while (j + 1 < len - 2 && nums[j] == nums[j + 1]) j++;
    	    }
    	    while (i + 1 < len - 3 && nums[i] == nums[i + 1]) i++;
    	}
    	return result;
    }
};