class Solution {	// Author: Xinyu Chen
public:
    bool exist(vector<vector<char>>& board, string word) {
		rows = board.size();
		if (rows == 0) return false;
		cols = board[0].size();
		if (cols == 0) return false;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (check(board, word, i, j)) return true;
			}
		}
		return false;
	}

	bool check(vector<vector<char>>& board, string word, int x, int y) {
		if (x < 0 || x >= rows) return false;
		if (y < 0 || y >= cols) return false;
		if (board[x][y] == '.') return false;
		if (board[x][y] != word[0]) return false;
		if (word.size() == 1) return true;
		word = word.substr(1);
		char c = board[x][y];
		board[x][y] = '.';
		if (check(board, word, x - 1, y)
		|| check(board, word, x, y - 1)
		|| check(board, word, x + 1, y)
		|| check(board, word, x, y + 1))
			return true;
		board[x][y] = c;
		return false;
	}
private:
    int rows, cols;
};