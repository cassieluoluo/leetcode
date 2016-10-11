public class Solution {
    public bool IsPowerOfTwo(int n) {
        if (n <= 0) return false;
        bool flag = false;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                if (flag) return false;
                else flag = true;
            }
            n >>= 1;
        }
        return flag;
    }
} // Author: XC
