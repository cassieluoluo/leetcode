class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        int same = k, diff = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            int temp_same = diff;
            int temp_diff = (diff + same) * (k - 1);
            same = temp_same;
            diff = temp_diff;
        }
        return same + diff;
    }
}; // Author: Xinyu Chen
