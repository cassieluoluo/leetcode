public class Solution {
    int[] dx = {-1, -1, -1, 0,  0,  1, 1 ,1};
    int[] dy = {-1,  0,  1, -1, 1, -1, 0, 1};
    public void GameOfLife(int[,] board) {
        int rows = board.GetLength(0);
        int cols = board.GetLength(1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int lives = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= rows || y < 0 || y >= cols) continue;
                    lives += board[x, y] & 1;
                }
                if ((board[i, j] & 1) == 0 && lives == 3) board[i, j] |= 2;
                if ((board[i, j] & 1) == 1 && (lives == 2 || lives == 3)) board[i, j] |= 2;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i, j] >>= 1;
            }
        }
    }
} // Author: XC
