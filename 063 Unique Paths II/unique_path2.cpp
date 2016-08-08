class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        if (rows == 0) return 0;
        int cols = obstacleGrid[0].size();
        vector<vector<int>> count(rows, vector<int>(cols, 0));
        count[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i < cols; i++)
            count[0][i] = obstacleGrid[0][i] == 0 ? count[0][i - 1] : 0;
        for (int i = 1; i < rows; i++)
            count[i][0] = obstacleGrid[i][0] == 0 ? count[i - 1][0] : 0;
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                count[i][j] = obstacleGrid[i][j] == 0 ?
                    count[i][j] = count[i - 1][j] + count[i][j - 1] : 0;
            }
        }
        return count[rows - 1][cols - 1];
    }
}; // Author: XC