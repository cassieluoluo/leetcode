class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);
        
        if (len1 == 0) return ((double)nums2[(len2 - 1)/2] + (double)nums2[len2/2])/2;
        int lo = 0, hi = len1 * 2;
        while (lo <= hi) {
            int c1 = (lo + hi) / 2;
            int c2 = len1 + len2 - c1;
            
            double l1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1)/2];
            double r1 = c1 == len1 * 2 ? INT_MAX : nums1[c1/2];
            double l2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1)/2];
            double r2 = c2 == len2 * 2 ? INT_MAX : nums2[c2/2];
            
            if (l1 > r2) hi = c1;
            else if (l2 > r1) lo = c1 + 1;
            else return (max(l1, l2) + min(r1, r2)) / 2;
        }
        return -1;
    }
}; // Author: XC
