public class Solution {
    public int Reverse(int x) {
        long res = 0;
        int data = x >= 0 ? x : -x;
        while (data > 0)
        {
            res *= 10;
            res += data%10;
            data /= 10;
        }
        if (res > Int32.MaxValue) return 0;
        return x >= 0 ? (int)res : (int)-res;
    }
} // Author: XC
