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
};  // Author: XC
