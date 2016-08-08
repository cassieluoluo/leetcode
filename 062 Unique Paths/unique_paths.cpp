class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> count(m, vector<int>(n, 1));
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                count[row][col] = count[row - 1][col] + count[row][col - 1];
            }
        }
        return count[m - 1][n - 1];
    }
}; // Author: XC
