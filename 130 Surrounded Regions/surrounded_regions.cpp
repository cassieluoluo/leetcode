class Solution {
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        if (rows == 0) return;
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            enqueue(board, i, 0);
            enqueue(board, i, cols - 1);
        }
        for (int i = 1; i < cols - 1; i++) {
            enqueue(board, 0, i);
            enqueue(board, rows - 1, i);
        }
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            int row = n / cols;
            int col = n % cols;
            board[row][col] = 'Y';
            enqueue(board, row - 1, col);
            enqueue(board, row + 1, col);
            enqueue(board, row, col - 1);
            enqueue(board, row, col + 1);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
    
    void enqueue(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return;
        if (board[x][y] != 'O') return;
        q.push(cols * x + y);
    }
private:
    int rows, cols;
    queue<int> q;
}; // Author: XC