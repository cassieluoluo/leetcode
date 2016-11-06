class Solution {
public:
     vector<vector<int>> combine(int n, int k) {
        vector<int> entry;
        helper(n, k, 1, entry);
        return result;
    }
    
    void helper(int n, int k, int curr, vector<int>& entry) {
        if (entry.size() == k) {
            result.push_back(entry);
            return;
        }
        for (int i = curr; i <= n; i++) {
            entry.push_back(i);
            helper(n, k, i + 1, entry);
            entry.pop_back();
        }
    }

private:
    vector<vector<int>> result;
}; // Author: XC
