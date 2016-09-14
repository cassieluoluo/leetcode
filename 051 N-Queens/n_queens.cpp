class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		rows = cols = n;
		vector<string> board(rows, string(cols, '.'));
		dfs(0, board);
		return result;
	}

	void dfs(int row, vector<string>& board) {
		if (row == rows) {
			result.push_back(board);
			return;
		}
		for (int col = 0; col < cols; ++col) {
			if (check_board(board, row, col)) {
				board[row][col] = 'Q';
				dfs(row + 1, board);
				board[row][col] = '.';
			}
		}
	}
	
	bool check_board(vector<string>& board, int row, int col) {
		for (int i = 0; i != row; ++i) {
			if (board[i][col] == 'Q') return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == 'Q') return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < cols; --i, ++j) {
			if (board[i][j] == 'Q') return false;
		}
		return true;
	}

	void print_board(vector<string>& board) {
		for (auto row : board) {
			cout << row << endl;
		}
		cout << endl;
	}
private:
	vector<vector<string>> result;
	int rows, cols;
}; // Author: XC