void dfs(char** grid, int gridRowSize, int gridColSize, int row, int col) {
    if (row < 0 || row >= gridRowSize || col < 0 || col >= gridColSize)
        return;
    if (grid[row][col] == '1') {
        grid[row][col] = '0';
        dfs(grid, gridRowSize, gridColSize, row - 1, col);
        dfs(grid, gridRowSize, gridColSize, row, col - 1);
        dfs(grid, gridRowSize, gridColSize, row + 1, col);
        dfs(grid, gridRowSize, gridColSize, row, col + 1);
    }
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize == 0) return 0;
    int i, j, count = 0;
    for (i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridRowSize, gridColSize, i, j);
            }
        }
    }
    return count;
} /* Author: XC */
