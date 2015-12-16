class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> row;
        dfs(n, k, 1, row);
        return result;
    }
    
    void dfs(int n, int k, int i, vector<int>& row) {
        if (i > n) return;
        for (int j = i; j <= n; j++) {
            row.push_back(j);
            if (row.size() == k) {
                result.push_back(row);
            }
            else {
                dfs(n, k, j + 1, row);
            }
            row.pop_back();
        }
    }
private:
    vector<vector<int>> result;
};
