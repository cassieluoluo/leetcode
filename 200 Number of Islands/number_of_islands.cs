public class Solution {
    private int count, rows, cols;
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};
    
    public int NumIslands(char[,] grid) {
        count = 0;
        rows = grid.GetLength(0);
        cols = grid.GetLength(1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i, j] == '1') count++;
                dfs(grid, i, j);
            }
        }
        return count;
    }
    
    private void dfs(char[,] grid, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return;
        if (grid[x, y] == '2' || grid[x, y] == '0') return;
        char ch = grid[x, y];
        grid[x, y] = '2';
        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dx[i], y + dy[i]);
        }
    }
} // Author: XC
