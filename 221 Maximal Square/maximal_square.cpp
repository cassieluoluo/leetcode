class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        int maxlen = 0;
        vector<vector<int>> res(2, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            res[i%2][0] = matrix[i][0] - '0';
            maxlen = max(maxlen, res[i%2][0]);
            for (int j = 1; j < cols; j++) {
                if (i == 0) res[0][j] = matrix[0][j] - '0';
                else {
                    if (matrix[i][j] == '0') res[i%2][j] = 0;
                    else res[i%2][j] = min(res[(i - 1)%2][j - 1],
                                       min(res[(i - 1)%2][j], res[i%2][j - 1])) + 1;
                }
                maxlen = max(maxlen, res[i%2][j]);
            }
        }
        return maxlen * maxlen;
    }
}; // Author: XC