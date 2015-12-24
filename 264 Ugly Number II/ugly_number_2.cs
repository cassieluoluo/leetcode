public class Solution {	// Author: Xinyu Chen
    public int NthUglyNumber(int n) {
        int c2 = 0, c3 = 0, c5 = 0;
        int v2 = 0, v3 = 0, v5 = 0;
        var numList = new List<int>();
        int current = 1;
        while (--n > 0)
        {
            numList.Add(current);
            c2 = numList[v2] * 2;
            c3 = numList[v3] * 3;
            c5 = numList[v5] * 5;
            current = Math.Min(c2, Math.Min(c3, c5));
            if (current == c2) v2++;
            if (current == c3) v3++;
            if (current == c5) v5++;
        }
        return current;
    }
}