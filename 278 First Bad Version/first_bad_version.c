// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isBadVersion(mid)) hi = mid;
        else lo = mid;
    }
    return isBadVersion(lo) ? lo : hi;
} /* Author: XC */