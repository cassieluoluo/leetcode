class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n);
		cols = vector<int>(n);
		diag = adiag = 0;
		num = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int mark = player == 1 ? 1 : -1;
		rows[row] += mark;
		cols[col] += mark;
		if (row == col) diag += mark;
		if (row + col == num - 1) adiag += mark;
		if (rows[row] == num || cols[col] == num) return 1;
		if (rows[row] == -num || cols[col] == -num) return 2;
		if (diag == num || adiag == num) return 1;
		if (diag == -num || adiag == -num) return 2;
		return 0;
    }
	
private:
	vector<int> rows, cols;
	int diag, adiag, num;
}; // Author: XC

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
