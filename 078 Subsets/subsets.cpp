class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> entry;
        helper(nums, entry, 0);
        return result;
    }
    
    void helper(vector<int>& nums, vector<int>& entry, int curr) {
        result.push_back(entry);
        for (int i = curr; i < nums.size(); i++) {
            entry.push_back(nums[i]);
            helper(nums, entry, i + 1);
            entry.pop_back();
        }
    }

private:
    vector<vector<int>> result;
}; // Author: XC
