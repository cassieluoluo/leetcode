class Solution {
public:
    int totalNQueens(int n) {
        total = 0;
        vector<int> board(n, -1);
        backtrack(board, n, 0);
        return total;
    }
    
private:   
    void backtrack(vector<int>& board, int n, int row) {
        if (row == n) {
            total++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (validate(board, row, i)) {
                board[row] = i;
                backtrack(board, n, row + 1);
                board[row] = -1;
            }
        }
    }
    
    bool validate(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col) return false;
            if (abs(i - row) == abs(board[i] - col)) return false;
        }
        return true;
    }
    int total;
}; // Author: XC