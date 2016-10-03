// DFS Solution
class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		rows = rooms.size();
		if (rows == 0) return;
		cols = rooms[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (rooms[i][j] == 0)
					helper(rooms, i, j, 0, true);
			}
		}
	}

private:
	void helper(vector<vector<int>>& rooms, int i, int j, int distance, bool entry) {
		if (i < 0 || i >= rows || j < 0 || j >= cols || rooms[i][j] == -1) return;
		if (rooms[i][j] == 0 && !entry) return;
		if (rooms[i][j] < distance) return;
		rooms[i][j] = distance;
		for (int k = 0; k < 4; k++) {
			helper(rooms, i + dx[k], j + dy[k], distance + 1, false);
		}
		
	}
	int rows, cols;
	const int dx[4] = { -1, 1, 0, 0 };
	const int dy[4] = { 0, 0, -1, 1 };
}; // Author: XC

// BFS Solution
class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		rows = rooms.size();
		if (rows == 0) return;
		cols = rooms[0].size();
		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (rooms[i][j] == 0)
					q.push(make_pair(i, j));
			}
		}
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			int x = p.first;
			int y = p.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
				if (rooms[nx][ny] < rooms[x][y] + 1) continue;
				rooms[x + dx[k]][y + dy[k]] = rooms[x][y] + 1;
				q.push(make_pair(x + dx[k], y + dy[k]));
			}
		}
	}
	int rows, cols;
	const int dx[4] = { -1, 1, 0, 0 };
	const int dy[4] = { 0, 0, -1, 1 };
}; // Author: XC