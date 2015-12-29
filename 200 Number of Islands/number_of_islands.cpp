class Solution {	// Author: Xinyu Chen
public:
    int numIslands(vector<vector<char>>& grid) {
		rows = grid.size();
		if (rows == 0) return 0;
		cols = grid[0].size();
		int result = 0;
		for (int row = 0; row < rows; ++row) {
			for (int col = 0; col < cols; ++col) {
				if (grid[row][col] == '1') {
					dfs(grid, row, col);
					result++;
				}
			}
		}
		return result;
	}
private:
	void dfs(vector<vector<char>>& grid, int x, int y) {
		if (x < 0 || x >= rows || y < 0 || y >= cols) return;
		char c = grid[x][y];
		if (c == '0' || c == '2') return;
		grid[x][y] = '2';
		dfs(grid, x - 1, y);
		dfs(grid, x, y - 1);
		dfs(grid, x + 1, y);
		dfs(grid, x, y + 1);
	}
	int rows, cols;
};