class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> entry;
        helper(candidates, target, entry, 0, result);
        return result;
    }
    
    void helper(vector<int>& c, int t, vector<int>& entry, int p, vector<vector<int>>& result) {
        if (t == 0) {
            result.push_back(entry);
            return;
        }
        for (int i = p; i < c.size(); i++) {
            if (c[i] > t) continue;
            if (i != p && c[i] == c[i - 1]) continue;
            entry.push_back(c[i]);
            helper(c, t - c[i], entry, i, result);
            entry.pop_back();
        }
    }
}; // Author: XC