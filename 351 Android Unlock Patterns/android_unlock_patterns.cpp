class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> crossing(9, vector<int>(9, -1));
		crossing[0][2] = crossing[2][0] = 1;
		crossing[3][5] = crossing[5][3] = 4;
		crossing[6][8] = crossing[8][6] = 7;
		crossing[0][6] = crossing[6][0] = 3;
		crossing[1][7] = crossing[7][1] = 4;
		crossing[2][8] = crossing[8][2] = 5;
		crossing[0][8] = crossing[8][0] = 4;
		crossing[2][6] = crossing[6][2] = 4;
		int result = 0;
		for (int i = m; i <= n; i++) {
			vector<int> visited(9);
			visited[0] = 1;
			result += dfs(0, i - 1, crossing, visited) * 4;
			visited = vector<int>(9);
			visited[1] = 1;
			result += dfs(1, i - 1, crossing, visited) * 4;
			visited = vector<int>(9);
			visited[4] = 1;
			result += dfs(4, i - 1, crossing, visited);
		}
		return result;
    }
	
	int dfs(int n, int rem, const vector<vector<int>>& crossing, vector<int>& visited) {
		if (rem == 0) return 1;
		int res = 0;
		for (int i = 0; i < 9; i++) {
			if (visited[i] == 1) continue;
			if (crossing[n][i] != -1 && visited[crossing[n][i]] == 0) continue;
			visited[i] = 1;
			res += dfs(i, rem - 1, crossing, visited);
			visited[i] = 0;
		}
		return res;
	}
}; // Author: XC
