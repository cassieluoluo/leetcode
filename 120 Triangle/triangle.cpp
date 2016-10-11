class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = (triangle[rows - 1].size());
        vector<int> dp(cols);
        for (int col = 0; col < cols; col++) {
            dp[col] = triangle[rows - 1][col];
        }
        for (int row = triangle.size() - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
            }
        }
        return dp[0];
    }
}; // Author: XC

