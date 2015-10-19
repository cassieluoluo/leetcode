/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Summary Ranges
 *	https://leetcode.com/problems/summary-ranges/
 *	Runtime: 0 ms
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
	    if (nums.empty()) return result;
    	string buffer;
    	for (int i = 0; i < nums.size() - 1; i++) {
    		bool first = false;
    		if (buffer.empty()) {
    			buffer = to_string(nums[i]);
    			first = true;
    		}
    		if (nums[i + 1] != nums[i] + 1) {
    			if (first) result.push_back(buffer);
    			else {
    				buffer.append("->");
    				buffer.append(to_string(nums[i]));
    				result.push_back(buffer);
    			}
    			buffer.clear();
    		}
    	}
    	int last = nums[nums.size() - 1];
    	if (!buffer.empty()) buffer.append("->");
    	buffer.append(to_string(last));
    	result.push_back(buffer);
    	return result;
    }
};