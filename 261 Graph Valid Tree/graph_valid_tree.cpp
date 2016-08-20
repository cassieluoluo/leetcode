class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> hash(n, -1);
        for (int i = 0; i < n; i++) {
            hash[i] = -1;
        }
        for (int i = 0; i < edges.size(); i++) {
            int r1 = find(hash, edges[i][0]);
            int r2 = find(hash, edges[i][1]);
            if (r1 == r2) return false;
            hash[r2] = r1;
        }
        return true;
    }
    
    int find(vector<int>& hash, int x) {
        if (hash[x] == -1) return x;
        int ac = hash[x];
        while (hash[ac] != -1)
            ac = hash[ac];
        hash[x] = ac;
        return ac;
    }
}; // Author: XC