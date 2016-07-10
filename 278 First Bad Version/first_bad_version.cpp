// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        int lo = 1, hi = n, mid;
        while (lo + 1 < hi) {
            mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
}; // Author: XC