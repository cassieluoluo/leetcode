class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> entry;
		len = nums.size();
		sort(nums.begin(), nums.end());
        vector<bool> visited(len);
        helper(nums, visited, entry);
        return result;
    }
    
    void helper(vector<int>& nums, vector<bool>& visited, vector<int>& entry) {
        if (entry.size() == len) {
            result.push_back(entry);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited[i]) continue;
            entry.push_back(nums[i]);
            visited[i] = true;
            helper(nums, visited, entry);
            entry.pop_back();
            visited[i] = false;
            while (i < len - 1 && nums[i] == nums[i + 1]) i++;
        }
    }

private:
    vector<vector<int>> result;
	int len;
}; // Author: XC
