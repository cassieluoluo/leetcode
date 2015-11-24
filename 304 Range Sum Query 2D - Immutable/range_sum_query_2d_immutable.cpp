class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        sums = vector<vector<int>>(rows, vector<int>(cols));
        sums[0][0] = matrix[0][0];
        for (int i = 1; i < rows; i++) {
            sums[i][0] = sums[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < cols; i++) {
            sums[0][i] = sums[0][i - 1] + matrix[0][i];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                sums[i][j] = matrix[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = 0, top = 0, dup = 0;
        if (row1 != 0 && col1 != 0) {
            left = sums[row1 - 1][col2];
            top = sums[row2][col1 - 1];
            dup = sums[row1 - 1][col1 - 1];
        }
        else if (row1 != 0) {
            top = sums[row1 - 1][col2];
        }
        else if (col1 != 0) {
            left = sums[row2][col1 - 1];
        }
        return sums[row2][col2] - left - top + dup;
    }
private:
    vector<vector<int>> sums;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);