public class Solution {
    public void wallsAndGates(int[][] rooms) {
        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[0].length; j++) {
                if (rooms[i][j] == 0) {
                    helper(rooms, i, j, 0);
                }
            }
        }
    }
    
    private void helper(int[][] rooms, int i, int j, int dist) {
        if (i >= rooms.length || i < 0 || j >= rooms[0].length || j < 0 || rooms[i][j] < dist) return;
        rooms[i][j] = dist;
        helper(rooms, i + 1, j, dist + 1);
        helper(rooms, i - 1, j, dist + 1);
        helper(rooms, i, j + 1, dist + 1);
        helper(rooms, i, j - 1, dist + 1);
    }
} // Author: Cassie
