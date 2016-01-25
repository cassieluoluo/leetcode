class Solution {  // Author: Xinyu Chen
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> group;
        dfs(nums, group, result);
        return result;
    }
    
    void dfs(vector<int>& nums, vector<int>& group, vector<vector<int>>& result) {
        if (group.size() == nums.size()) {
            result.push_back(group);
            return;
        }
        for (auto n : nums) {
            if (find(group.begin(), group.end(), n) == group.end()) {
                group.push_back(n);
                dfs(nums, group, result);
                group.pop_back();
            }
        }
    }
};
