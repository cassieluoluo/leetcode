class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> entry;
        helper(nums, entry, 0);
        return result;
    }
    
    void helper(vector<int>& nums, vector<int>& entry, int curr) {
        result.push_back(entry);
        for (int i = curr; i < len; i++) {
            entry.push_back(nums[i]);
            helper(nums, entry, i + 1);
            entry.pop_back();
            while (i < len - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    
private:
    vector<vector<int>> result;
    int len;
}; // Author: XC
