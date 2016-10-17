class Solution {
public:
    double myPow(double x, int n) {
        long m = n;
        if (m < 0) return helper(1.0 / x, -m);
        return helper(x, m);
    }

private:
    double helper(double x, long n) {
        if (n == 0) return 1.0;
        double t = helper(x, n / 2);
        if (n % 2 == 0) return t * t;
        return x * t * t;
    }
}; // Author: XC
