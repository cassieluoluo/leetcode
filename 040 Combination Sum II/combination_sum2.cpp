class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> entry;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, entry, 0, result);
        return result;
    }
    
    void helper(vector<int>& c, int t, vector<int>& entry, int p, vector<vector<int>>& result) {
        if (t == 0) {
            result.push_back(entry);
            return;
        }
        for (int i = p; i < c.size(); i++) {
            if (c[i] > t) return;
            if (i != p && c[i] == c[i - 1]) continue;
            entry.push_back(c[i]);
            helper(c, t - c[i], entry, i + 1, result);
            entry.pop_back();
        }
    }
}; // Author: XC