public class Solution {
    private char[] template;
    private int rows;
    private List<List<String>> result;
    public List<List<String>> solveNQueens(int n) {
        template = new char[n];
        rows = n;
        result = new ArrayList<List<String>>();
        for (int i = 0; i < n; i++) template[i] = '.';
        int[] row = new int[n];
        solve(row, 0);
        return result;
    }
    
    private void solve(int[] row, int curr) {
        if (curr == rows) {
            result.add(generate(row));
            return;
        }
        for (int i = 0; i < rows; i++) {
            row[curr] = i;
            if (check(row, curr, i))
                solve(row, curr + 1);
            row[curr] = 0;
        }
    }
    
    private boolean check(int[] row, int r, int c) {
        for (int i = 0; i < r; i++) {
            if (row[i] == c) return false;
            if (Math.abs(row[i] - c) == Math.abs(i - r)) return false;
        }
        return true;
    }
    
    private List<String> generate(int[] row) {
        List<String> res = new ArrayList<String>();
        for (int i = 0; i < rows; i++) {
            char[] line = template.clone();
            line[row[i]] = 'Q';
            String s = new String(line);
            res.add(s);
        }
        return res;
    }
} // Author: XC