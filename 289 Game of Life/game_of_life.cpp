class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int h = board.size();
        if (h == 0) return;
        int w = board[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                vector<pair<int, int>> pairs{
                    make_pair(i - 1, j - 1),
                    make_pair(i - 1, j),
                    make_pair(i - 1, j + 1),
                    make_pair(i, j - 1),
                    make_pair(i, j + 1),
                    make_pair(i + 1, j - 1),
                    make_pair(i + 1, j),
                    make_pair(i + 1, j + 1)
                };
                int live = 0;
                for (auto p : pairs) {
                    if (p.first < 0 || p.first >= h || p.second < 0 || p.second >= w)
                        continue;
                    live += board[p.first][p.second] & 1;
                }
                if (!(board[i][j] & 1)) {
                    if (live == 3) board[i][j] |= 2;
                    else board[i][j] &= ~2;
                }
                else {
                    if (live < 2 || live > 3) board[i][j] &= ~2;
                    else board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                board[i][j] >>= 1;
            }
        }
    }
}; // Author: XC
