class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (char c = '1'; c <= '9'; c++) {
                    if (validate(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool validate(vector<vector<char>>& board, int i, int j, char c) {
		for (int col = 0; col < 9; col++)
			if (board[i][col] == c) return false;
		for (int row = 0; row < 9; row++)
			if (board[row][j] == c) return false;
		for (int row = (i / 3) * 3; row < (i / 3 + 1) * 3; row++)
			for (int col = (j / 3) * 3; col < (j / 3 + 1) * 3; col++)
				if (board[row][col] == c) return false;
		return true;
	}
};