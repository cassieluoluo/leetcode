class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		rows = grid.size();
		if (rows == 0) return 0;
		cols = grid[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> sums(rows, vector<int>(cols, -1));
		int space = 0, res = numeric_limits<int>::max();
		int count = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1) {
					count++;
					q.push(make_pair(i, j));
					vector<vector<int>> dist(rows, vector<int>(cols, 0));
					while (!q.empty()) {
						auto p = q.front();
						q.pop();
						int x = p.first;
						int y = p.second;
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
							if (grid[nx][ny] == space) {
								dist[nx][ny] = dist[x][y] + 1;
								if (sums[nx][ny] == -1) sums[nx][ny] = 0;
								sums[nx][ny] += dist[nx][ny];
								grid[nx][ny]--;
								q.push(make_pair(nx, ny));
							}
						}
					}
					space--;
				}
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] + count == 0)
					res = min(res, sums[i][j]);
			}
		}
		return res == numeric_limits<int>::max() ? -1 : res;
	}
	int rows, cols;
	const int dx[4] = { -1, 1, 0, 0 };
	const int dy[4] = { 0, 0, -1, 1 };
}; // Author: XC
